/*
    Complexity - O(P logG)

    Observe that the naive solution is O(GP) as for every incoming plane the algorithm iterates
    over the gates.
    By using a binary search tree to store the available gate #s at all times, the complexity to
    compute the largest available gate # under a certain value becomes logarithmic with respect
    to the # of gates.
    Note that std::set in c++ is an implementation of a binary search tree.
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define nl "\n"

const int mxGP = 1e5;
int G, P, plane[mxGP + 1], ans;
set<int> gates;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> G >> P;
    for(int i = 1; i <= P; ++i)
        cin >> plane[i];

    for(int i = 1; i <= G; ++i)
        gates.insert(i);

    for(int i = 1; i <= P; ++i) {
        if(gates.count(plane[i])) {
            gates.erase(plane[i]);
            ++ans;
        }
        else {
            if(gates.lower_bound(plane[i]) == gates.begin())
                break;
            else if(*--gates.lower_bound(plane[i]) >= plane[i])
                break;
            else {
                gates.erase(--gates.lower_bound(plane[i]));
                ++ans;
            }
        }
    }

    cout << ans;
    return 0;
}
