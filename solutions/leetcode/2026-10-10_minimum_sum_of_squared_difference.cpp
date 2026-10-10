#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        const int MAXV = 100000; // max possible diff
        vector<long long> freq(MAXV + 1, 0);
        int maxDiff = 0;
        for (int i = 0; i < n; ++i) {
            int d = abs(nums1[i] - nums2[i]);
            freq[d]++;
            if (d > maxDiff) maxDiff = d;
        }
        long long ops = (long long)k1 + k2;
        int cur = maxDiff;
        while (ops > 0 && cur > 0) {
            if (freq[cur] == 0) { cur--; continue; }
            // find next lower value with non-zero frequency
            int nxt = cur - 1;
            while (nxt > 0 && freq[nxt] == 0) nxt--;
            long long cnt = freq[cur];
            long long step = cur - nxt; // distance to next level
            long long need = step * cnt;
            if (ops >= need) {
                // move all to nxt
                freq[nxt] += cnt;
                freq[cur] = 0;
                ops -= need;
                cur = nxt;
            } else {
                long long dec = ops / cnt; // full decrements per element
                long long rem = ops % cnt;
                int newVal = cur - (int)dec;
                freq[cur] = 0;
                freq[newVal] += cnt - rem;
                if (rem > 0) freq[newVal - 1] += rem;
                ops = 0;
                cur = newVal;
            }
        }
        long long result = 0;
        if (ops > 0) {
            // all diffs are zero now
            long long q = ops / n;
            long long r = ops % n;
            result = (n - r) * q * q + r * (q + 1) * (q + 1);
        } else {
            for (int d = 0; d <= MAXV; ++d) {
                if (freq[d]) {
                    result += freq[d] * (long long)d * (long long)d;
                }
            }
        }
        return result;
    }
};