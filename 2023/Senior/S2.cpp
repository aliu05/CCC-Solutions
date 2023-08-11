#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

const int mxN = 5000;
int N, h[mxN], ans[mxN+1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> h[i];

    for(int i = 1; i <= N; ++i)
        ans[i] = INT_MAX;

    // Odd length crops
    ans[1] = 0;
    for(int i = 0; i < N; ++i) {
        int l, r, lastCrop, thisCrop;
        l = i - 1;
        r = i + 1;
        lastCrop = 0;
        while(l >= 0 && r < N) {
            thisCrop = lastCrop + abs(h[l] - h[r]);
            lastCrop = thisCrop;
            if(thisCrop < ans[r - l + 1])
                ans[r - l + 1] = thisCrop;
            --l, ++r;
        }
    }
    // Even length crops
    for(int i = 0; i < N - 1; ++i) {
        int l, r, lastCrop, thisCrop;
        l = i;
        r = i + 1;
        lastCrop = 0;
        while(l >= 0 && r < N) {
            thisCrop = lastCrop + abs(h[l] - h[r]);
            lastCrop = thisCrop;
            if(thisCrop < ans[r - l + 1])
                ans[r - l + 1] = thisCrop;
            --l, ++r;
        }
    }

    for(int i = 1; i <= N; ++i)
        cout << ans[i] << " ";
    return 0;
}
/*
    Complexity: O(N^2)

    Observe that all brute force solutions to this problem are O(N^3) because they use linear time
    to compute the "asymetric value" of each crop of each length.
    The key is to use a fixed midpoint and expanding outwards, the "asymetric value" can be found
    in constant time. This is done by adding the difference of each new pair of h[l] and h[r] to
    the previous "asymetric value" in iteration.
    Note that we must consider midpoints between adjacent mountains to account for crops of even length.
*/
