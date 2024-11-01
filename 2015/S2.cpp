/*
    Complexity - O(J + A)
    
    Since each jersey may only be assigned to at most one athlete, we can greedily add 1 to the
    sum of satisfied athletes if an athlete is satisfied with the jersey with their number while
    it is still available. We must then remove the jersey's availability before proceeding to
    the next athlete.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

const int mxJA = 1e6;
int J, A, ans;
char jersey[mxJA + 1];
bool taken[mxJA + 1];
pair<char, int> athlete[mxJA];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> J >> A;
    for(int i = 1; i <= J; ++i)
        cin >> jersey[i];
    for(int i = 0; i < A; ++i)
        cin >> athlete[i].first >> athlete[i].second;
        
    for(int i = 0; i < A; ++i) {
        // Conveniently 'L' < 'M' < 'S'
        if(jersey[athlete[i].second] <= athlete[i].first && !taken[athlete[i].second]) {
            ++ans;
            taken[athlete[i].second] = true;
        }
    }
    
    cout << ans << nl;
    return 0;
}
