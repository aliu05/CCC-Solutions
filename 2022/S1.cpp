/*
    Complexity - O(N)

    Since the input is guaranteed to obey (N <= 10^6), it is sufficient to iterate through about
    N/5 integers representing all the possible amount of 5s we can include in the sum, then
    increment the answer if the rest needed is divisible by 4.
*/

#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;

#define nl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    i64 N, ans;
    cin >> N;
    ans = 0;
    for(i64 i = 0; i <= N / 5; ++i) {
        if((N - 5 * i) % 4 == 0) ans++;
    }
    cout << ans;
    return 0;
}
