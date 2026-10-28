#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minXorPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MAXX = 1024; // 0..1023
        vector<vector<array<char, MAXX>>> dp(m, vector<array<char, MAXX>>(n));
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                dp[i][j].fill(0);
        dp[0][0][grid[0][0]] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;
                int val = grid[i][j];
                if (i > 0) {
                    for (int x = 0; x < MAXX; ++x) {
                        if (dp[i-1][j][x]) dp[i][j][x ^ val] = 1;
                    }
                }
                if (j > 0) {
                    for (int x = 0; x < MAXX; ++x) {
                        if (dp[i][j-1][x]) dp[i][j][x ^ val] = 1;
                    }
                }
            }
        }
        for (int x = 0; x < MAXX; ++x) {
            if (dp[m-1][n-1][x]) return x;
        }
        return 0; // should never reach here
    }
};