#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        long long X, Y;
        cin >> X >> Y;
        long long floorX = (X - 1) / 10 + 1;
        long long floorY = (Y - 1) / 10 + 1;
        cout << llabs(floorX - floorY);
        if (T) cout << '\n';
    }
    return 0;
}