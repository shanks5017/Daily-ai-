#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        long long P, Q, R, S;
        cin >> P >> Q >> R >> S;
        long long sum = P + Q + R + S;
        bool monopoly = false;
        if (P > sum - P) monopoly = true;
        else if (Q > sum - Q) monopoly = true;
        else if (R > sum - R) monopoly = true;
        else if (S > sum - S) monopoly = true;
        cout << (monopoly ? "YES" : "NO") << '\n';
    }
    return 0;
}