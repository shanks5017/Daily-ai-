#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minScore(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = LLONG_MAX;
        for (int i = 0; i <= 2; ++i) {
            for (int j = 0; j <= 2 - i; ++j) {
                if (i + j >= n) continue; // need at least one element left
                long long range = (long long)nums[n - 1 - j] - (long long)nums[i];
                ans = min(ans, range);
            }
        }
        return (int)ans;
    }
};