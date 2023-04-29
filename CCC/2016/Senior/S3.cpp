#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

struct Node {
	bool dest=false;
	int parent=-1;
	vector<int> children;
};

const int mxNM=1e5;
int N, M;
vector<int> adj[mxNM];
Node r[mxNM];

//when you reach end; if(adj[end_node_index].size()==0), take damage
void removal(Node n) {
	if(n.children.size()==0) {
		
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for(int i=0; i<M; ++i) {
		int t; cin >> t;
		r[t].dest=true;
	}
	for(int i=0; i<N-1; ++i) {
		int s, t; cin >> s >> t;
		adj[s].push_back(t);
	}
	// use adj list to construct Node array
	for(int i=0; i<N; ++i) {
		for(int e : adj[i]) {
			r[i].children.push_back(e);
			r[e].parent=i;
		}
	}
	// remove "unecessary" nodes
	removal(r[0]);
	return 0;
}
// remove "unecessary" nodes
// find diameter of remaining graph
// start at an endpoint of diameter and dfs to count the most optimal path