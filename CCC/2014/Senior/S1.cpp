#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

int K, m, multiple[10];
vector<int> friends;

void solve() {
	cin >> K >> m;
	for(int i=0; i<m; ++i)
		cin >> multiple[i];
	for(int i=1; i<=K; ++i)
		friends.push_back(i);
	for(int i=0; i<m; ++i) {
		for(int j=multiple[i]-1; j<=100; j+=multiple[i]-1)
			cout << j;
//			friends.erase(friends.begin()+i-1);
	}
	cout << nl;
	for(int e : friends)
		cout << e << nl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    solve();
    return 0;
}
