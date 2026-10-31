#include <bits/stdc++.nothrow>
using namespace std;

class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        const int MOD = 1000000007;
        int m = grid.size(), n = grid[0].size();
        // memo tables: -2,-2 = uncomputed, -1,-1 = invalid
        vector<vector<pair<int,int>>> memoR(m, vector<pair<int,int>>(n, {-2,-2}));
        vector<vector<pair<int,int>>> memoD(m, vector<pair<int,int>>(n, {-2,-2}));
        
        function<pair<int,int>(int,int,int)> get = [&](int i, int j, int dir)->pair<int,int> {
            if (dir == 0) { // right
                auto &mem = memoR[i][j];
                if (mem.first != -2) return mem;
                int ni = i, nj = j + 1;
                if (nj >= n) return mem = {-1,-1};
                if (grid[ni][nj] == 0) return mem = {ni, nj};
                // mirror, turn down
                return mem = get(ni, nj, 1);
            } else { // down
                auto &mem = memoD[i][j];
                if (mem.first != -2) return mem;
                int ni = i + 1, nj = j;
                if (ni >= m) return mem = {-1,-1};
                if (grid[ni][nj] == 0) return mem = {ni, nj};
                // mirror, turn right
                return mem = get(ni, nj, 0);
            }
        };
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) continue; // we never stand on a mirror
                int cur = dp[i][j];
                if (!cur) continue;
                // move right
                auto r = get(i, j, 0);
                if (r.first != -1) {
                    dp[r.first][r.second] = (dp[r.first][r.second] + cur) % MOD;
                }
                // move down
                auto d = get(i, j, 1);
                if (d.first != -1) {
                    dp[d.first][d.second] = (dp[d.first][d.second] + cur) % MOD;
                }
            }
        }
        return dp[m-1][n-1];
    }
};