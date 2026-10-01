#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long R, O, C;
    if (!(cin >> R >> O >> C)) return 0;
    long long maxAdditional = (20 - O) * 36;
    if (C + maxAdditional > R) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}