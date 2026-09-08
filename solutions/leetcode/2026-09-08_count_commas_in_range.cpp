#include <bits/stdc++.h>
using namespace std;

long long countCommas(long long n) {
    long long ans = 0;
    long long start = 1000; // 10^3
    long long commas = 1;   // numbers with 4-6 digits have 1 comma
    while (start <= n) {
        long long end = min(n, start * 1000 - 1);
        long long cnt = end - start + 1;
        ans += cnt * commas;
        start *= 1000;
        ++commas;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    bool first = true;
    while (cin >> n) {
        long long res = countCommas(n);
        if (!first) cout << '\n';
        first = false;
        cout << res;
    }
    return 0;
}