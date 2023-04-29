#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

const int mxAJ=1e6;
int J, A, jer[mxAJ+1], ans;
pair<int, int> req[mxAJ];

void solve() {
    cin >> J >> A;
    for(int i=1; i<=J; ++i) {
        char temp;
        cin >> temp;
        if(temp=='S')
            jer[i]=1;
        else if(temp=='M')
            jer[i]=2;
        else
            jer[i]=3;
    }
    for(int i=0; i<A; ++i) {
        char temp;
        cin >> temp >> req[i].second;
        if(temp=='S')
            req[i].first=1;
        else if(temp=='M')
            req[i].first=2;
        else
            req[i].first=3;
    }
    for(int i=0; i<A; ++i) {
        if(jer[req[i].second]>=req[i].first) {
            jer[req[i].second]=0;
            ++ans;
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    solve();
    return 0;
}