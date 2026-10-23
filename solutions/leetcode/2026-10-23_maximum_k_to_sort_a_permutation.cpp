#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumK(vector<int>& nums) {
        int n = nums.size();
        bool sorted = true;
        for (int i = 0; i < n; ++i) if (nums[i] != i) { sorted = false; break; }
        if (sorted) return 0;
        int maxBit = 0;
        while ((1 << maxBit) <= n - 1) ++maxBit;
        int k = 0;
        for (int b = maxBit; b >= 0; --b) {
            int cand = k | (1 << b);
            bool ok = true;
            for (int i = 0; i < n && ok; ++i) {
                bool in_i = ((i & cand) == cand);
                bool in_num = ((nums[i] & cand) == cand);
                if (in_i != in_num) { ok = false; break; }
                if (!in_i && i != nums[i]) { ok = false; break; }
            }
            if (ok) k = cand;
        }
        return k;
    }
};