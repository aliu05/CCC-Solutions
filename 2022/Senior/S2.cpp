/*
    Complexity - O(G * (logX + logY))

    Observe that naive solutions which keep the conditions in arrays have complexity
    O(G * (X + Y)) because they iterate through all X + Y conditions for every group G.
    As this is not fast enough for the final subtask, we can avoid the O(X + Y) iteration steps
    for each group by using hashing. 

    Note that a O(G(1)) solution is possible by mapping every name to an stl unordered_set instead 
    of a logarithm set. However, even with the log complexity, our solution passes comfortably.
*/

#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;

#define nl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    i64 X, Y, G;
    unordered_map<string, set<string> > same, diff;
    cin >> X;
    for(int i = 0; i < X; ++i) {
        string n1, n2;
        cin >> n1 >> n2;
        same[n1].insert(n2);
        same[n2].insert(n1);
    }
    cin >> Y;
    for(int i = 0; i < Y; ++i) {
        string n1, n2;
        cin >> n1 >> n2;
        diff[n1].insert(n2);
        diff[n2].insert(n1);
    }
    cin >> G;
    vector<vector<string> > group(G, vector<string>(3));
    for(int i = 0; i < G; ++i) {
        cin >> group[i][0] >> group[i][1] >> group[i][2];
    }

    // Initially, assume all X same conditions are violated
    // When we find a same condition is satisfied, subtract 1 from the answer
    // Also increment the sum for every diff condition violated
    i64 ans = X;
    for(vector<string> e : group) {
        // Same conditions
        if(same[e[0]].count(e[1])) ans--;
        if(same[e[0]].count(e[2])) ans--;
        if(same[e[1]].count(e[2])) ans--;
        // Diff conditions
        if(diff[e[0]].count(e[1])) ans++;
        if(diff[e[0]].count(e[2])) ans++;
        if(diff[e[1]].count(e[2])) ans++;
    }
    cout << ans;
    return 0;
}
