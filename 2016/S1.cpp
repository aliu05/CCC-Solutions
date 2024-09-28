/*
    Complexity - O(N)
    
    Count how often every letter appears in the first and second string.
    If and only if any letter appears more times in the second string than it did in the first,
    the strings cannot be anagrams of each other.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

string s1, s2;
int count1[128], count2[128], N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s1 >> s2;

    N = s1.size();
    for(int i = 0; i < s1.size(); ++i) {
        ++count1[s1[i]];
        ++count2[s2[i]];
    }
    for(int i = 0; i < 128; ++i) {
        if(i != 42) {
            if(count2[i] > count1[i]) {
                cout << 'N';
                return 0;
            }
        }
    }
    
    cout << 'A';
    return 0;
}
