/*
    Complexity - O(N logN)

    Begin by sorting all of the observed tide heights.
    The first half of the sorted tide heights are taken during low tide and the second half are
    taken during high tide. We print the highest low tides first and lowest high tides first in
    our answer, alternating between low and high.
    Remember to consider what happens when N is odd.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

const int mxN = 100;
int N, tide[mxN], low[mxN], high[mxN];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> tide[i];
        
    sort(tide, tide + N);
    for(int i = 0; i < N / 2; ++i) {
        low[i] = tide[i];
        high[i] = tide[(N + 1) / 2 + i];
    }
    if(N % 2)
        low[N / 2] = tide[N / 2];
    
    for(int i = 0; i < N / 2; ++i)
        cout << low[(N + 1) / 2 - i - 1] << " " << high[i] << " ";
    if(N % 2)
        cout << low[0];
    return 0;
}
