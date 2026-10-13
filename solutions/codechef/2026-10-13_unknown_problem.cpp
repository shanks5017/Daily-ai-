#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        int r1, r2, r3, r4;
        cin >> r1 >> r2 >> r3 >> r4;
        if (r1 == 0 && r2 == 0 && r3 == 0 && r4 == 0)
            cout << "IN";
        else
            cout << "OUT";
        if (T) cout << '\n';
    }
    return 0;
}