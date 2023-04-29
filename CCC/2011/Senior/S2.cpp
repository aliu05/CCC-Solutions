#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

const int mxN=1e4;
int N, ans;
char a[mxN];


void solve() {
	cin >> N;
	for(int i=0; i<N; ++i)
		cin >> a[i];
	for(int i=0; i<N; ++i) {
		char temp;
		cin >> temp;
		if(temp==a[i])
			++ans;
	}
	cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}