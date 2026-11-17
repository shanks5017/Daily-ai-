#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;
        vector<vector<int>> cost(n, vector<int>(n, INF));
        // precompute cost for all substrings length >=2
        for (int l = 0; l < n; ++l) {
            for (int r = l + 1; r < n; ++r) {
                int len = r - l + 1;
                int best = INF;
                for (int d = 1; d < len; ++d) {
                    if (len % d) continue;
                    int groups = d;
                    int per = len / d; // length of each group
                    int cur = 0;
                    for (int offset = 0; offset < groups; ++offset) {
                        for (int t = 0; t < per / 2; ++t) {
                            int p1 = l + offset + t * d;
                            int p2 = l + offset + (per - 1 - t) * d;
                            if (s[p1] != s[p2]) ++cur;
                        }
                    }
                    best = min(best, cur);
                }
                cost[l][r] = best;
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, INF));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                for (int p = 0; p <= i - 2; ++p) { // ensure length >=2
                    if (dp[p][j - 1] == INF) continue;
                    int c = cost[p][i - 1];
                    if (c == INF) continue;
                    dp[i][j] = min(dp[i][j], dp[p][j - 1] + c);
                }
            }
        }
        return dp[n][k];
    }
};