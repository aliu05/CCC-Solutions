#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

int units[8], patients[8], ans;

void op(int* u, int* p) {
	int transfer=min(*u, *p);
	*u-=transfer;
	*p-=transfer;
	ans+=transfer;
}

void solve() {
	for(int i=0; i<8; ++i)
		cin >> units[i];
	for(int i=0; i<8; ++i)
		cin >> patients[i];
	op(units, patients);
	op(units+1, patients+1);
	op(units, patients+1);
	op(units+2, patients+2);
	op(units, patients+2);
	op(units+4, patients+4);
	op(units, patients+4);
	op(units+3, patients+3);
	op(units+2, patients+3);
	op(units+1, patients+3);
	op(units, patients+3);
	op(units+5, patients+5);
	op(units+4, patients+5);
	op(units+1, patients+5);
	op(units, patients+5);
	op(units+6, patients+6);
	op(units, patients+6);
	op(units+2, patients+6);
	op(units+4, patients+6);
	op(units, patients+7);
	op(units+1, patients+7);
	op(units+2, patients+7);
	op(units+3, patients+7);
	op(units+4, patients+7);
	op(units+5, patients+7);
	op(units+6, patients+7);
	op(units+7, patients+7);
	cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	solve();
    return 0;
}