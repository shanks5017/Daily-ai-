#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long pow10 = 1;
        for (int d = 1; ; ++d) {
            long long L = (d == 1) ? 1 : pow10;
            if (L > n) break;
            long long nextPow = pow10 * 10;
            long long R = min(n, nextPow - 1);
            long long cnt = R - L + 1;
            long long c = (d - 1) / 3;
            ans += cnt * c;
            pow10 = nextPow;
        }
        return ans;
    }
};