#include <bits/stdc++.h>
using namespace std;

long long ceil_div(long long a, long long b) {
    if (a <= 0) return 0;
    return (a + b - 1) / b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        long long H, X, Y;
        cin >> H >> X >> Y;
        long long without_special = ceil_div(H, X);
        long long with_special = 1 + ceil_div(H - Y, X);
        if (H - Y <= 0) with_special = 1; // ensure non-negative division
        long long ans = min(without_special, with_special);
        cout << ans << '\n';
    }
    return 0;
}