#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

const int mxK=1e5;
int K, num[mxK], ans;
vector<int> st;

void solve() {
	cin >> K;
	for(int i=0; i<K; ++i)
		cin >> num[i];
	for(int i=0; i<K; ++i) {
		if(num[i]==0) {
			ans-=st.back();
			st.pop_back();
		}
		else {
			ans+=num[i];
			st.push_back(num[i]);
		}
	}
	cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}