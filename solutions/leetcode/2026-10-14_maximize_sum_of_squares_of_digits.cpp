#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string maxScore(int num, int sum) {
        long long maxPossible = 9LL * num;
        if (sum < 1 || sum > maxPossible) return "";
        string res;
        long long remaining = sum;
        for (int i = 0; i < num; ++i) {
            int start = (i == 0) ? 1 : 0;
            bool placed = false;
            for (int d = 9; d >= start; --d) {
                long long rem = remaining - d;
                long long maxRem = 9LL * (num - i - 1);
                if (rem >= 0 && rem <= maxRem) {
                    res.push_back('0' + d);
                    remaining = rem;
                    placed = true;
                    break;
                }
            }
            if (!placed) return "";
        }
        if (remaining != 0) return "";
        return res;
    }
};