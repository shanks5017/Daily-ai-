#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        long long N, X;
        cin >> N >> X;
        if (X % N == 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}