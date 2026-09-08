#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        long long A, B, C, D;
        cin >> A >> B;
        cin >> C >> D;
        if (C >= A && D >= B) {
            cout << "POSSIBLE\n";
        } else {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}