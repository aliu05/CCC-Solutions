/*
    Complexity - O(N logN)
    
    For question 1, we will always pair the fastest bikers from one country with the fastest
    from the other. This is in order to prevent any slow bikers from getting "carried", thus
    minimizing the total speed.
    For question 2, we will simply inverse this logic and pair one country's fastest bikers
    with the other country's slowest.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

const int mxN = 100;
int question, N, d[mxN], p[mxN], ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> question >> N;
    for(int i = 0; i < N; ++i)
        cin >> d[i];
    for(int i = 0; i < N; ++i)
        cin >> p[i];
        
    sort(d, d + N);
    sort(p, p + N);

    if(question == 1) {
        for(int i = 0; i < N; ++i)
            ans += min(d[i], p[i]);
    }
    else {
        for(int i = 0; i < N; ++i)
            ans += min(d[i], p[N - 1 - i]);
    }
    
    cout << ans;
    return 0;
}
