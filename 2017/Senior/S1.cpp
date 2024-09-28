/*
    Complexity - O(N)
    
    Simulate the cumulative sum of scores for both teams.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

const int mxN = 1e5;
int N, swift[mxN + 1], semaphore[mxN + 1], ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 1; i <= N; ++i)
        cin >> swift[i];
    for(int i = 1; i <= N; ++i)
        cin >> semaphore[i];
    
    for(int i = 1; i <= N; ++i) {
        swift[i] += swift[i - 1];
        semaphore[i] += semaphore[i - 1];
    }
    for(int i = 0; i <= N; ++i) {
        if(swift[i] == semaphore[i])
            ans = i;
    }
    
    cout << ans;
    return 0;
}
