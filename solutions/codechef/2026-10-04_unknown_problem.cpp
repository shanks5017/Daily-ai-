#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        long long N, X, K;
        cin >> N >> X >> K;
        long long can = K / X;
        long long ans = min(N, can);
        cout << ans;
        if (T) cout << '\n';
    }
    return 0;
}