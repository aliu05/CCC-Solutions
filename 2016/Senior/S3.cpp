/*
    Complexity - O(N)
    
    Observe that for most trees, the optimal route does not include some set of nodes.
    Naturally, the first step is to remove these unvisited nodes from our tree.
    We must keep any node which is a pho restaurant itself, or it is a part of the path
    needed to reach a pho restaurant further down one of it's "branches".
    We will use the recursive property of depth first search (dfs) to accomplish this step.

    Now that we have the compressed tree, observe that we must visit all nodes on this tree
    at least once using the least amount of steps.
    Since Jo cannot teleport, she might have to travel across some edges twice.
    Intuitively, Jo should travel along a diameter of the tree to minimize backtracking edges.
    The fastest way to reach all nodes can be expressed as:
    2 * (# of nodes in compressed tree - 1) - length of the diameter

    Note that we can compute the diameter of a tree in linear time with the following algorithm:
    1. Find the furthest node from any arbitrary starting node.
    2. Return the furthest possible distance relative to this node.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

const int mxN = 1e5;
int N, M, dist[mxN];
bool pho[mxN], deleted[mxN], vis[mxN];
vector<int> adj[mxN];

bool dfsPrune(int x) {
    vis[x] = true;
    bool keep = false;
    for(int restaurant : adj[x]) {
        if(vis[restaurant])
            continue;
        if(dfsPrune(restaurant))
            keep = true;
    }
    if(pho[x] || keep)
        return true;
    else {
        deleted[x] = true;
        return false;
    }
}

void dfsDiameter(int x, int pathLength) {
    if(deleted[x])
        return;

    vis[x] = true;
    dist[x] = pathLength;
    ++pathLength;
    for(int restaurant : adj[x]) {
        if(vis[restaurant])
            continue;
        dfsDiameter(restaurant, pathLength);
    }
}

int start() {
    int node = 0;
    for(int i = 0; i < N; ++i) {
        if(deleted[i])
            continue;
        if(dist[i] > dist[node])
            node = i;
    }
    
    return node;
}

int furthest() {
    int distance = 0;
    for(int i = 0; i < N; ++i) {
        if(deleted[i])
            continue;
        if(dist[i] > distance)
            distance = dist[i];
    }
    
    return distance;
}

int newN() {
    int ret = 0;
    for(int i = 0; i < N; ++i) {
        if(!deleted[i])
            ++ret;
    }
    
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for(int i = 0; i < M; ++i) {
        int inp;
        cin >> inp;
        pho[inp] = true;
    }
    for(int i = 0; i < N - 1; ++i) {
        int inp1, inp2;
        cin >> inp1 >> inp2;
        adj[inp1].push_back(inp2);
        adj[inp2].push_back(inp1);
    }
    
    // Remove unvisited nodes
    for(int i = 0; i < N; ++i) {
        if(pho[i]) {
            dfsPrune(i);
            break;
        }
    }
    
    // Find diameter
    memset(vis, false, N);
    for(int i = 0; i < N; ++i) {
        if(!deleted[i]) {
            dfsDiameter(i, 0);
            break;
        }
    }
    int st = start();
    memset(vis, false, N);
    for(int i = 0; i < N; ++i)
        dist[i] = 0;
    dfsDiameter(st, 0);

    cout << 2 * (newN() - 1) - furthest();
    return 0;
}
