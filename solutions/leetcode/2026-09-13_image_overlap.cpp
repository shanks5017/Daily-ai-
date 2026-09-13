#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> a, b;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (img1[i][j]) a.emplace_back(i, j);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (img2[i][j]) b.emplace_back(i, j);
        if (a.empty() || b.empty()) return 0;
        unordered_map<long long,int> cnt;
        int best = 0;
        for (auto &p1 : a) {
            for (auto &p2 : b) {
                int dx = p2.first - p1.first;
                int dy = p2.second - p1.second;
                long long key = (static_cast<long long>(dx) << 32) ^ (dy & 0xffffffffLL);
                int cur = ++cnt[key];
                if (cur > best) best = cur;
            }
        }
        return best;
    }
};