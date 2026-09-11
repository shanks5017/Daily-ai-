#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        long long A, X, B, Y;
        cin >> A >> X >> B >> Y;
        long long left = A * Y;
        long long right = B * X;
        if (left > right) cout << "ALICE";
        else if (left < right) cout << "BOB";
        else cout << "EQUAL";
        if (T) cout << '\n';
    }
    return 0;
}