#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        int need = (x + 1) / 2;
        vector<long long> cost(n, 0); // only first n-x+1 used
        
        multiset<long long> left, right;
        long long sumL = 0, sumR = 0;
        auto rebalance = [&]() {
            while ((int)left.size() > need) {
                auto it = prev(left.end());
                long long val = *it;
                left.erase(it);
                sumL -= val;
                right.insert(val);
                sumR += val;
            }
            while ((int)left.size() < need && !right.empty()) {
                auto it = right.begin();
                long long val = *it;
                right.erase(it);
                sumR -= val;
                left.insert(val);
                sumL += val;
            }
        };
        auto add = [&](long long v) {
            if (left.empty() || v <= *prev(left.end())) {
                left.insert(v);
                sumL += v;
            } else {
                right.insert(v);
                sumR += v;
            }
            rebalance();
        };
        auto remove = [&](long long v) {
            auto it = left.find(v);
            if (it != left.end()) {
                left.erase(it);
                sumL -= v;
            } else {
                it = right.find(v);
                if (it != right.end()) {
                    right.erase(it);
                    sumR -= v;
                }
            }
            rebalance();
        };
        
        for (int i = 0; i < n; ++i) {
            add(nums[i]);
            if (i >= x - 1) {
                long long med = *prev(left.end());
                long long curCost = med * (long long)left.size() - sumL + sumR - med * (long long)right.size();
                cost[i - x + 1] = curCost;
                remove(nums[i - x + 1]);
            }
        }
        
        const long long INF = (1LL<<60);
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));
        dp[0][0] = 0;
        for (int i = 0; i < n; ++i) {
            for (int cnt = 0; cnt <= k; ++cnt) {
                long long cur = dp[i][cnt];
                if (cur == INF) continue;
                // skip current element
                if (dp[i + 1][cnt] > cur) dp[i + 1][cnt] = cur;
                // take window starting at i
                if (cnt + 1 <= k && i + x <= n) {
                    long long nd = cur + cost[i];
                    if (dp[i + x][cnt + 1] > nd) dp[i + x][cnt + 1] = nd;
                }
            }
        }
        return dp[n][k];
    }
};