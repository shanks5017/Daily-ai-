#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        long long X, Y, Z;
        cin >> X >> Y >> Z;
        long long travel = Y / X;
        long long wait = Z - travel;
        if (wait < 0) wait = 0;
        cout << wait;
        if (T) cout << '\n';
    }
    return 0;
}