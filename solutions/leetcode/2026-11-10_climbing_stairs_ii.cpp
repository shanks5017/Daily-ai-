#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCostClimbingStairsII(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            long long c = costs[i - 1];
            for (int k = 1; k <= 3; ++k) {
                if (i - k >= 0) {
                    dp[i] = min(dp[i], dp[i - k] + c + 1LL * k * k);
                }
            }
        }
        return dp[n];
    }
};