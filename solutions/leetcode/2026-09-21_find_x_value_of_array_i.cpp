#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> findXValues(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> cnt(k, 0), newcnt(k, 0);
        for (int val : nums) {
            int a = val % k;
            fill(newcnt.begin(), newcnt.end(), 0);
            // extend previous subarrays
            for (int m = 0; m < k; ++m) {
                if (cnt[m] == 0) continue;
                int nm = (m * a) % k;
                newcnt[nm] += cnt[m];
            }
            // start new subarray at current element
            newcnt[a] += 1;
            // accumulate to result
            for (int m = 0; m < k; ++m) {
                result[m] += newcnt[m];
            }
            cnt.swap(newcnt);
        }
        return result;
    }
};