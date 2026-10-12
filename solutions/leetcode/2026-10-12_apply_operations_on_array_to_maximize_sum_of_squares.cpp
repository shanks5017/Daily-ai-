#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1000000007LL;
        const int MAXB = 31;
        long long cnt[MAXB] = {0};
        for (int x : nums) {
            for (int b = 0; b < MAXB; ++b) {
                if (x & (1 << b)) cnt[b]++;
            }
        }
        long long ans = 0;
        for (int i = 0; i < k; ++i) {
            long long cur = 0;
            for (int b = 0; b < MAXB; ++b) {
                if (cnt[b] > 0) {
                    cur |= (1LL << b);
                    cnt[b]--;
                }
            }
            __int128 sq = (__int128)cur * cur;
            ans = (ans + (long long)(sq % MOD)) % MOD;
        }
        return (int)ans;
    }
};