/*
    Complexity - O(NM)

    This problem can be solved with 3 different letters and some case work.
    The general approach is to fill R rows and C colums with 'a', then all other slots with 'b'.
    A row or column with only 1 type of letter will naturally always be a palindrome.
    However, this approach fails in a few edge cases.
    Follow the if statements to find how I dealt with these trickier cases.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

const int mxNM = 2000;
int N, M, R, C;
char ans[mxNM][mxNM];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> R >> C;
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j)
            ans[i][j] = 'a';
    }

    if(R == 0 && C == 0) {
        ans[0][0] = 'c';
        for(int i = 1; i < N; ++i)
            ans[i][0] = 'b';
        for(int i = 1; i < M; ++i)
            ans[0][i] = 'b';
    }
    else if(R == 0) {
        for(int i = 0; i < N; ++i)
            ans[i][0] = 'b';
        for(int i = 0; i < M - C; ++i)
            ans[0][i] = 'c';
    }
    else if(C == 0) {
        for(int i = 0; i < M; ++i)
            ans[0][i] = 'b';
        for(int i = 0; i < N - R; ++i)
            ans[i][0] = 'c';
    }
    else if(R == N) {
        if(M % 2 == 0 && C % 2 == 1) {
            cout << "IMPOSSIBLE";
            return 0;
        }
        for(int i = 0; (i + 1) * 2 <= M - C; ++i) {
            ans[0][i] = 'b';
            ans[0][M - i - 1] = 'b';
        }
        if((M - C) % 2 == 1)
            ans[0][M / 2] = 'b';
    }
    else if(C == M) {
        if(N % 2 == 0 && R % 2 == 1) {
            cout << "IMPOSSIBLE";
            return 0;
        }
        for(int i = 0; (i + 1) * 2 <= N - R; ++i) {
            ans[i][0] = 'b';
            ans[N - i - 1][0] = 'b';
        }
        if((N - R) % 2 == 1)
            ans[N / 2][0] = 'b';
    }
    else {
        for(int i = 0; i < N - R; ++i) {
            for(int j = 0; j < M - C; ++j)
                ans[i][j] = 'b';
        }
    }
    
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j)
            cout << ans[i][j];
        cout << nl;
    }
    return 0;
}
