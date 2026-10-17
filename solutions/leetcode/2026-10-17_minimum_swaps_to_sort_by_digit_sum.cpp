#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int digitSum(int x) {
        int s = 0;
        while (x) {
            s += x % 10;
            x /= 10;
        }
        return s;
    }
    
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<pair<int,int>, int>> arr; // ((digitSum, value), original index)
        arr.reserve(n);
        for (int i = 0; i < n; ++i) {
            arr.push_back({{digitSum(nums[i]), nums[i]}, i});
        }
        sort(arr.begin(), arr.end(), [](const auto& a, const auto& b){
            if (a.first.first != b.first.first) return a.first.first < b.first.first;
            return a.first.second < b.first.second;
        });
        // map value to target index
        unordered_map<int,int> targetPos;
        targetPos.reserve(n*2);
        for (int i = 0; i < n; ++i) {
            targetPos[arr[i].first.second] = i;
        }
        vector<int> to(n);
        for (int i = 0; i < n; ++i) {
            to[i] = targetPos[nums[i]];
        }
        vector<char> visited(n, 0);
        int cycles = 0;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            int cur = i;
            int len = 0;
            while (!visited[cur]) {
                visited[cur] = 1;
                cur = to[cur];
                ++len;
            }
            if (len > 0) ++cycles;
        }
        return n - cycles;
    }
};