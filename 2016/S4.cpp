/*
    Complexity - O(N^3)

    This solution uses a 2D boolean dp array where state dp[i][j] represents whether the entire
    range from index i to j inclusive, [i, j], can be combined into one riceball (with a size that
    we can determine by keeping prefix sum of input array). We can populate our dp table by
    iterating over all possible lengths of combined segments in order from small to large as large
    riceballs must itself be made up of smaller riceballs. Then at each length we determine all
    possible combinations and update the dp table. Finally, the answer will simply be the largest
    riceball constructed by combining any range [i, j] where dp[i][j]=true.

    In order to avoid a O(N^4) solution, which is too slow for (N <= 400) we can notice that a
    two-pointer approach can be used in the innermost loop for trying to combine 3 segments A|B|C
    where size of A == C. The idea is if we represent the boundary between A and B with a left
    pointer and boundary between B and C with a right pointer, then manipulate the pointers in
    linear time to check whether a specific range can be combined.
*/

#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;

#define nl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    i64 n; cin >> n;
    vector<i64> a(n+1);
    for(i64 i = 1; i <= n; ++i) cin >> a[i];

    vector<i64> psum(n+1);
    psum[0] = 0;
    for(i64 i = 1; i <= n; ++i) psum[i] = psum[i-1] + a[i];

    // Can you combine all elements in [i, j]
    vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));
    for(i64 i = 1; i <= n; ++i) dp[i][i] = true;

    // Small to large lengths
    for(i64 l = 2; l <= n; ++l) {
        for(i64 st = 1; st+l-1 <= n; ++st) {
            // Try combining 2 segments
            for(i64 i = st; i < st+l && i < n; ++i) {
                if(dp[st][i] && dp[i+1][st+l-1] && psum[st+l-1]-psum[i] == psum[i]-psum[st-1])
                    dp[st][st+l-1] = true;
            }
            // Try combining 3 segments
            i64 rp = min(n-1, st+l-1);
            for(i64 lp = st; lp < st+l && lp < n && lp < rp; ++lp) {
                bool canCombine = (dp[st][lp] && dp[lp+1][rp] && dp[rp+1][st+l-1]);
                i64 sum1, sum2;
                sum1 = psum[lp] - psum[st-1];
                sum2 = psum[st+l-1] - psum[rp];
                if(canCombine && sum1 == sum2) {
                    dp[st][st+l-1] = true;
                    break;
                }

                if(sum1 > sum2) {
                    rp--;
                    lp--; // to counter the increment in loop
                }
            }
        }
    }

    i64 ans = 0;
    for(i64 i = 1; i <= n; ++i) {
        for(i64 j = 1; j <= n; ++j) {
            if(dp[i][j]) ans = max(ans, psum[j] - psum[i-1]);
        }
    }

    cout << ans;
    return 0;
}
