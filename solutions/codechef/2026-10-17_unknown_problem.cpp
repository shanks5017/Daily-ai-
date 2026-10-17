#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        long long N, X, P;
        cin >> N >> X >> P;
        long long score = 4 * X - N;
        if (score >= P) cout << "PASS\n";
        else cout << "FAIL\n";
    }
    return 0;
}