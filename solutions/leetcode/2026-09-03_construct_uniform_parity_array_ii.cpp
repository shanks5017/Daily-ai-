#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeUniformParity(vector<int>& nums1) {
        const int INF = 2e9;
        int minOdd = INF, minEven = INF;
        int cntOdd = 0, cntEven = 0;
        for (int x : nums1) {
            if (x % 2) {
                cntOdd++;
                minOdd = min(minOdd, x);
            } else {
                cntEven++;
                minEven = min(minEven, x);
            }
        }
        if (cntOdd == 0 || cntEven == 0) return true;
        return minOdd < minEven;
    }
};