/*
    Complexity - O(N)

    Simulate the inputs that do or do not contribute toward the final sum by keeping a stack.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

const int mxN = 1e5;
int N, inp[mxN], ans;
vector<int> stk;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; ++i)
        cin >> inp[i];

    for(int i = 0; i < N; ++i) {
        if(inp[i] == 0)
            stk.pop_back();
        else
            stk.push_back(inp[i]);
    }
    for(int e : stk)
        ans += e;

    cout << ans;
    return 0;
}
