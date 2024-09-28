/*
    Complexity - O(N)

    Observe that each triangle will add a side length of 3 unless it has an edge directly adjacent
    to another triangle.
    Therefore the answer is just 3 times the # of triangles minus 2 for each adjacent set of edges.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

const int mxN = 2e5;
int N, inp[2][mxN], ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < N; ++j) {
            cin >> inp[i][j];
            if(inp[i][j])
                ans += 3;
        }   
    }
    
    for(int i = 0; i < N - 1; ++i) {
        if(inp[0][i]) {
            if(inp[0][i + 1])
                ans -= 2;
            if(inp[1][i] && i % 2 == 0)
                ans -= 2;
        }
        if(inp[1][i] && inp[1][i + 1]) {
            ans -= 2;
        }
    }
    
    if(N % 2 == 1 && inp[0][N - 1] && inp[1][N - 1])
        ans -= 2;
    cout << ans;
    return 0;
}
