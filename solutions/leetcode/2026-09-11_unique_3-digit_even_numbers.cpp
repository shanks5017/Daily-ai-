#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countEvenNumbers(vector<int>& digits) {
        int freq[10] = {0};
        for (int d : digits) ++freq[d];
        int ans = 0;
        for (int num = 100; num <= 999; ++num) {
            if (num % 2 != 0) continue; // must be even
            int d1 = num / 100;
            int d2 = (num / 10) % 10;
            int d3 = num % 10;
            if (d1 == 0) continue; // no leading zero
            int need[10] = {0};
            ++need[d1];
            ++need[d2];
            ++need[d3];
            bool ok = true;
            for (int i = 0; i < 10; ++i) {
                if (need[i] > freq[i]) { ok = false; break; }
            }
            if (ok) ++ans;
        }
        return ans;
    }
};