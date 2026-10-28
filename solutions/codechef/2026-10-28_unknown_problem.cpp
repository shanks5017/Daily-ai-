#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        long long N;
        cin >> N;
        long long coins = N - N / 5;
        cout << coins << '\n';
    }
    return 0;
}