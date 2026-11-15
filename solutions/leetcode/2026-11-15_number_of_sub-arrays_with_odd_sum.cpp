#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& arr) {
        const long long MOD = 1000000007LL;
        long long countEven = 1, countOdd = 0;
        long long ans = 0;
        int parity = 0; // 0 even, 1 odd
        for (int num : arr) {
            parity ^= (num & 1);
            if (parity) {
                ans = (ans + countEven) % MOD;
                ++countOdd;
            } else {
                ans = (ans + countOdd) % MOD;
                ++countEven;
            }
        }
        return (int)ans;
    }
};