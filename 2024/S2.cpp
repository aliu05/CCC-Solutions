/*
    Complexity - O(TN)

    This is a simple implementation problem. We must count the frequency of each letter and for all
    letters with a greater frequency than 1, it must be followed by a letter with frequency of
    exactly one and vice-versa. This is most easily accomplished with a frequency array of size
    26 for all lowercase letters.
*/

#include <bits/stdc++.h>
using namespace std;

typedef int64_t i64;

#define nl "\n"

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    i64 t, n; cin >> t >> n;
    while(t--) {
        string s; cin >> s;
        vector<i64> freq(26, 0);
        for(char c : s) freq[c-'a']++;
        bool ans = true;
        for(i64 i = 1; i < n; ++i) {
            if(freq[s[i]-'a'] > 1 && freq[s[i-1]-'a'] > 1) ans = false;
            if(freq[s[i]-'a'] == 1 && freq[s[i-1]-'a'] == 1) ans = false;
        }
        cout << (ans? "T\n" : "F\n");
    }
    return 0;
}
