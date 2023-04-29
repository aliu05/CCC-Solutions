#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

int N, t_count, s_count;
string s;

void solve() {
	cin >> N;
	getline(cin, s);
	for(int i=0; i<N; ++i) {
		getline(cin, s);
		for(char e : s) {
			if(e=='t' || e=='T')
				++t_count;
			if(e=='s' || e=='S')
				++s_count;
		}
	}
	if(t_count>s_count)
		cout << "English";
	else
		cout << "French";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}