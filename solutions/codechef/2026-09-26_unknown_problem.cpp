#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        long long N, A, B;
        cin >> N >> A >> B;
        long long odd = (N + 1) / 2;
        long long even = N / 2;
        long long total = odd * B + even * A;
        cout << total;
        if (T) cout << '\n';
    }
    return 0;
}