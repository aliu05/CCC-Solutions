#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

int T, m;
ll x, y;

bool isCrystal(int m, int x, int y) {
	if(m==0)
		return false;
	if(y<pow(5, m-1) && x>=pow(5, m-1) && x<4*pow(5, m-1))
		return true;
	if(y<2*pow(5, m-1)) {
		if(x>=2*pow(5, m-1) && x<3*pow(5, m-1))
			return true;
		if(x<pow(5, m-1) || x>=4*pow(5, m-1))
			return false;
		if(x<2*pow(5, m-1)) {
			if(isCrystal(m-1, x-pow(5, m-1), y-pow(5, m-1)))
				return true;
			else
				return false;
		}
		else {
			if(isCrystal(m-1, x-3*pow(5, m-1), y-pow(5, m-1)))
				return true;
			else
				return false;
		}
	}
	if(y<3*pow(5, m-1) && x>=2*pow(5, m-1) && x<3*pow(5, m-1)) {
		if(isCrystal(m-1, x-2*pow(5, m-1), y-2*pow(5, m-1)))
			return true;
		else 
			return false;
	}
	return false;
}

void solve() {
	cin >> m >> x >> y;
	cout << (isCrystal(m, x, y) ? "crystal\n":"empty\n"); 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--)
		solve();
    return 0;
}