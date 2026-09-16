#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1000000007;
        vector<vector<int>> pref(n, vector<int>(k + 1, 0));
        vector<vector<int>> sumPref(n, vector<int>(k + 1, 0));
        // base cnt = 0
        for (int i = 0; i < n; ++i) {
            pref[i][0] = 1;
            sumPref[i][0] = (i == 0 ? 1 : (sumPref[i - 1][0] + 1) % MOD);
        }
        for (int cnt = 1; cnt <= k; ++cnt) {
            for (int pos = 0; pos < n; ++pos) {
                long long g = (pos == 0) ? 0 : sumPref[pos - 1][cnt - 1];
                long long prev = (pos == 0) ? 0 : pref[pos - 1][cnt];
                long long cur = (prev + g) % MOD;
                pref[pos][cnt] = (int)cur;
                long long sumPrev = (pos == 0) ? 0 : sumPref[pos - 1][cnt];
                sumPref[pos][cnt] = (int)((sumPrev + cur) % MOD);
            }
        }
        return pref[n - 1][k];
    }
};