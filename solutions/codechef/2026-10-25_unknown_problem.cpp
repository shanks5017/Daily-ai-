#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        long long X, Y, R;
        cin >> X >> Y >> R;
        long long total;
        if (R == 0) {
            total = X; // maximum possible sticks eaten without extra reward
        } else {
            long long extra = R / 30;
            total = X + extra;
        }
        long long plates = (total + Y - 1) / Y;
        cout << plates << '\n';
    }
    return 0;
}