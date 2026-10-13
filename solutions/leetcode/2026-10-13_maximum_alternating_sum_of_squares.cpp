#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxAlternatingScore(vector<int>& nums) {
        int n = nums.size();
        int k = (n + 1) / 2; // number of plus positions
        vector<long long> sq(n);
        long long total = 0;
        for (int i = 0; i < n; ++i) {
            long long v = 1LL * nums[i] * nums[i];
            sq[i] = v;
            total += v;
        }
        nth_element(sq.begin(), sq.begin() + k, sq.end(), greater<long long>());
        long long sumTop = 0;
        for (int i = 0; i < k; ++i) sumTop += sq[i];
        return 2 * sumTop - total;
    }
};