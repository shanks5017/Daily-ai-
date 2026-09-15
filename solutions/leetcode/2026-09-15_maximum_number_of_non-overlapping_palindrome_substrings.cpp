#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<int>> palEnds(n);
        for (int c = 0; c < n; ++c) {
            int l = c, r = c;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 >= k) palEnds[l].push_back(r);
                --l; ++r;
            }
            l = c; r = c + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 >= k) palEnds[l].push_back(r);
                --l; ++r;
            }
        }
        const int NEG = -1e9;
        vector<int> dp(n + 1, NEG);
        dp[0] = 0;
        for (int i = 0; i < n; ++i) {
            dp[i + 1] = max(dp[i + 1], dp[i]);
            for (int r : palEnds[i]) {
                dp[r + 1] = max(dp[r + 1], dp[i] + 1);
            }
        }
        return dp[n];
    }
};