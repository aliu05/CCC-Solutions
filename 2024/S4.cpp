/*
    Complexity - O(N + M)

    Our goal is to paint the edges in a graph such that all pairs of nodes directly connected by
    an edge must have a path alternating between red and blue colored edges. Considering that 2
    nodes being directly connected implies that they are in the same connected component (CC),
    we can consider individual CCs of the graph seperately and without loss of correctness.

    The idea is rather simple: for each individual CC in the input graph, begin a graph traversal
    at any arbitrary node. We will use an array to keep track of visited nodes, preventing cycles
    and thus creating a spanning tree of the CC with (node_count - 1) edges included. Furthermore,
    we separate the edges of this spanning tree into 2 groups, based on the edges' distance % 2
    from the root (or any other node would work too as root is chosen arbitrarily) and assign a
    color to each group of edges. Given that this is a spanning tree, we know that no unecessary
    edges are being painted, as well as having an alternating path between any 2 originally
    adjacent nodes due to our coloring protocool.

    Conviniently, no disjoint sets are needed as we can simply keep a global visited array and
    iterate through all nodes, begining a dfs rooted at a given node iff that node has not been
    marked visited by previous traversals.
*/

#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;

void dfs(i64 cur, bool color, const vector<vector<pair<i64, i64>>>& adj, vector<bool>& vis, vector<char>& ans) {
    vis[cur] = true;
    for(pair<i64, i64> e : adj[cur]) {
        if(vis[e.first]) continue;
        ans[e.second] = (color? 'B' : 'R');
        dfs(e.first, !color, adj, vis, ans);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    i64 n, m;
    cin >> n >> m;
    vector<vector<pair<i64, i64>>> adj(n);
    vector<char> ans(m, 'G');
    for(i64 i = 0; i < m; ++i) {
        i64 u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    vector<bool> vis(n, false);
    // Starts an arbitrarily rooted dfs once in each connected component
    for(i64 i = 0; i < n; ++i) {
        if(!vis[i]) dfs(i, false, adj, vis, ans);
    }

    for(char c : ans) cout << c;
    return 0;
}
