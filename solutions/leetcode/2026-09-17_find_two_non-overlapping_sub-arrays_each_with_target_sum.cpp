#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        const int INF = 1e9;
        int n = arr.size();
        vector<int> leftEnd(n, INF), rightStart(n, INF);
        long long sum = 0;
        int l = 0;
        for (int r = 0; r < n; ++r) {
            sum += arr[r];
            while (sum > target && l <= r) {
                sum -= arr[l];
                ++l;
            }
            if (sum == target) {
                int len = r - l + 1;
                leftEnd[r] = len;
                rightStart[l] = min(rightStart[l], len);
            }
        }
        vector<int> leftMin(n, INF), rightMin(n, INF);
        for (int i = 0; i < n; ++i) {
            leftMin[i] = (i == 0) ? leftEnd[i] : min(leftMin[i - 1], leftEnd[i]);
        }
        for (int i = n - 1; i >= 0; --i) {
            rightMin[i] = (i == n - 1) ? rightStart[i] : min(rightMin[i + 1], rightStart[i]);
        }
        int ans = INF;
        for (int i = 0; i < n - 1; ++i) {
            if (leftMin[i] < INF && rightMin[i + 1] < INF) {
                ans = min(ans, leftMin[i] + rightMin[i + 1]);
            }
        }
        return ans == INF ? -1 : ans;
    }
};