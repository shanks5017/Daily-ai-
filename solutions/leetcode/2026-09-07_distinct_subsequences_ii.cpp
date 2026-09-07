#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007LL;
        int n = s.size();
        vector<long long> dp(n + 1, 0);
        dp[0] = 1; // empty subsequence
        vector<int> last(26, -1);
        for (int i = 1; i <= n; ++i) {
            int c = s[i - 1] - 'a';
            dp[i] = (dp[i - 1] * 2) % MOD;
            if (last[c] != -1) {
                dp[i] = (dp[i] - dp[last[c] - 1] + MOD) % MOD;
            }
            last[c] = i;
        }
        long long ans = (dp[n] - 1 + MOD) % MOD; // exclude empty subsequence
        return (int)ans;
    }
};