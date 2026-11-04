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
        long long total = N * X;
        long long pizzas = (total + 4 - 1) / 4;
        cout << pizzas;
        if (T) cout << '\n';
    }
    return 0;
}