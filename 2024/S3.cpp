/*
    Complexity - O(N)

    The main observation is is that for the sequence to be "solvable", no two swipes in opposite
    directions (with different starting A_i) can cross over each other (share some range of
    indicies). Otherwise, whichever swipe is performed before the other will make it impossible
    to perform the other one. We can therefore determine whether a given starting sequence is
    solvable by compressing B by removing adjacent values which are the same and check if it this
    compressed B is a subsequence of A. If and only if compressed B is a subsequence of A, the 
    answer is YES.

    There are many viable approaches to finding a sequence of swipes in the YES case. In this
    implementation, we leverage the fact that we already know that in the YES case, no two swipes
    in opposite directions cross and the compressed B is a subsequence of A. The algorithm 
    identifies "sources" in A where the source A_i is responsible for painting some subarray
    so that it matches B. Some casework is needed so we ensure we respect the (K <= N) condition
    imposed by the problem. This is all done using pointers in linear time.
*/

#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;

#define nl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    i64 n; cin >> n;
    vector<i64> a(n), b(n);
    for(i64& e : a) cin >> e;
    for(i64& e : b) cin >> e;

    vector<i64> bSeq;
    for(i64 e : b) {
        if((i64)bSeq.size() == 0 || e != bSeq.back()) bSeq.push_back(e);
    }
    // Verify that B sequence is a subsequence of base A
    i64 bp = 0;
    bool can = false;
    for(i64 i = 0; i < n; ++i) {
        if(a[i] == bSeq[bp]) bp++;
        if(bp == (i64)bSeq.size()) {
            can = true;
            break;
        }
    }

    if(can) cout << "YES\n";
    else {
        cout << "NO";
        return 0;
    }
    vector<pair<i64, i64>> lans, rans;
    i64 ai = 0, bi = 0;
    for(i64 bsi = 0; bsi < (i64)bSeq.size(); ++bsi) {
        pair<i64, i64> bound;
        bound.first = bi;
        while(bi < n && b[bi] == bSeq[bsi]) bi++;
        bound.second = bi-1;

        while(ai < n && a[ai] != bSeq[bsi]) ai++;

        // In case of ai == bound, we don't need swipe; no double swipe in same direction
        // These rules ensure the condition for (K <= N)
        if(ai > bound.first) lans.emplace_back(bound.first, ai);
        else if(ai > bound.second) lans.emplace_back(bound.second, ai);
        if(ai < bound.second) rans.emplace_back(ai, bound.second);
        else if(ai < bound.first) rans.emplace_back(ai, bound.first);
    }

    cout << ((i64)lans.size() + (i64)rans.size()) << nl;
    for(pair<i64, i64> pii : lans) cout << "L " << pii.first << ' ' << pii.second << nl;
    reverse(rans.begin(), rans.end());
    for(pair<i64, i64> pii : rans) cout << "R " << pii.first << ' ' << pii.second << nl;

    return 0;
}
