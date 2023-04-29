#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

const int mxGP=1e5;
int G, P, planes[mxGP];
set<int> gates;

void solve() {
	cin >> G >> P;
	for(int i=0; i<P; ++i)
		cin >> planes[i];
	for(int i=1; i<=G; ++i)
		gates.insert(i);
	for(int i=0; i<P; ++i){
		if(*gates.upper_bound(planes[i])==*gates.begin() && planes[i]<*gates.begin()) {
			cout << i;
			return;
		}
		gates.erase(--gates.upper_bound(planes[i]));
	}
	cout << P;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}