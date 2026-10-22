#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        long long ans = LLONG_MAX;
        // Check rotation
        int k_rot = nums[0];
        bool ok_rot = true;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != (i + k_rot) % n) { ok_rot = false; break; }
        }
        if (ok_rot) {
            long long cand = min<long long>(k_rot, (long long)n - k_rot + 2);
            ans = min(ans, cand);
        }
        // Check reflection
        int first = nums[0];
        bool ok_ref = true;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != (first - i + n) % n) { ok_ref = false; break; }
        }
        if (ok_ref) {
            int k_ref = (first + 1) % n; // exponent in R L^k
            long long cand = 1 + min<long long>(k_ref, (long long)n - k_ref);
            ans = min(ans, cand);
        }
        if (ans == LLONG_MAX) return -1;
        return (int)ans;
    }
};