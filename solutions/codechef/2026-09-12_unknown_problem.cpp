#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        long long N, X, Y;
        cin >> N >> X >> Y;
        if (X == 0) {
            // Not possible per constraints, but handle gracefully
            cout << (Y == 0 ? "YES" : "NO") << '\n';
            continue;
        }
        if (Y % X == 0 && (Y / X) <= N) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}