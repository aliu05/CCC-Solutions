/*
    Complexity - O(K(N + Mlog(M))

    It is clear that because shortest time is a requirement, we must use Dijkstra's in some way to.
    To deal with the constraint of the hull thickness "cost" along paths, we can keep an extra
    dimension in the dp (distance) array since the hull thickness can only be (K <= 200) different
    values.

    Therefore, our dp matrix is represented as dp[node][hull thickness], where the shortest paths
    with respect to time considering all possible remaining hull thickness are stored. Transitions
    are still greedy just like with normal Dijkstra's because of our priority queue ordering.
*/

#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;

#define nl "\n"

struct CustomComp {
    // Smaller time, tiebreak with larger hull "health"
    bool operator()(const tuple<i64, i64, i64>& a, const tuple<i64, i64, i64>& b) {
        if(get<1>(a) == get<1>(b)) return get<2>(a) < get<2>(b);
        return get<1>(a) > get<1>(b);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    i64 K, N, M, A, B;
    cin >> K >> N >> M;
    vector<vector<tuple<i64, i64, i64>>> adj(N + 1); // 1: destination, 2: time, 3: hull wear
    for(i64 i = 0; i < M; ++i) {
        i64 a, b, t, w;
        cin >> a >> b >> t >> w;
        adj[a].emplace_back(b, t, w);
        adj[b].emplace_back(a, t, w);
    }
    cin >> A >> B;

    // Initialize dp with with all time INF
    vector<vector<i64>> dp(N + 1, vector<i64>(K + 1, LLONG_MAX));
    dp[A][K] = 0;
    // Initialize min pq for Dijsktra
    priority_queue<tuple<i64, i64, i64>, vector<tuple<i64, i64, i64>>, CustomComp> pq;
    pq.emplace(A, 0, K);

    while(!pq.empty()) {
        auto [node, time, hull] = pq.top();
        pq.pop();

        // Better path already found
        if(time > dp[node][hull]) continue;
        for(auto& nxt : adj[node]) {
            i64 nextNode = get<0>(nxt);
            i64 curTime = get<1>(nxt);
            i64 curHull = get<2>(nxt);
            i64 newTime = time + curTime;
            i64 newHull = hull - curHull;

            // Check if the hull remains intact and if this path is better
            if(newHull >= 0 && newTime < dp[nextNode][newHull]) {
                dp[nextNode][newHull] = newTime;
                pq.emplace(nextNode, newTime, newHull);
            }
        }
    }

    // Find best result at destination B
    i64 ans = LLONG_MAX;
    for(i64 i = 1; i <= K; ++i) ans = min(ans, dp[B][i]);
    cout << (ans < LLONG_MAX? ans : -1);
    return 0;
}
