#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        int a1,a2,a3,b1,b2,b3;
        cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
        int alice[3] = {a1,a2,a3};
        int bob[3] = {b1,b2,b3};
        sort(alice, alice+3, greater<int>());
        sort(bob, bob+3, greater<int>());
        int aliceScore = alice[0] + alice[1];
        int bobScore = bob[0] + bob[1];
        if (aliceScore > bobScore) cout << "Alice";
        else if (bobScore > aliceScore) cout << "Bob";
        else cout << "Tie";
        if (T) cout << '\n';
    }
    return 0;
}