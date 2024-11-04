/*
    Complexity - O(N)

    We can easily determine the index of the person sitting directly across from you as i + N/2.
    Therefore, it is sufficient to check this for half of the people and increment answer by 2
    for each match found.
*/

#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;

#define nl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    i64 n; cin >> n;
    vector<i64> a(n);
    for(i64& e : a) cin >> e;

    i64 ans = 0;
    for(i64 i = 0; i < n/2; ++i) {
        if(a[i] == a[i+n/2]) ans += 2;
    }
    cout << ans;
    return 0;
}
