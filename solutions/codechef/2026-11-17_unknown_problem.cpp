#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        long long dx = llabs(x1 - x2);
        long long dy = llabs(y1 - y2);
        cout << max(dx, dy) << '\n';
    }
    return 0;
}