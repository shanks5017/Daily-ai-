#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        struct Log {int server; int time;};
        vector<Log> v;
        v.reserve(logs.size());
        for (auto &lg : logs) v.push_back({lg[0], lg[1]});
        sort(v.begin(), v.end(), [](const Log& a, const Log& b){return a.time < b.time;});
        
        int m = v.size();
        vector<pair<int,int>> qs;
        qs.reserve(queries.size());
        for (int i = 0; i < (int)queries.size(); ++i) qs.emplace_back(queries[i], i);
        sort(qs.begin(), qs.end());
        
        vector<int> cnt(n+1, 0);
        int active = 0;
        int left = 0, right = 0;
        vector<int> ans(queries.size());
        
        for (auto [q, idx] : qs) {
            while (right < m && v[right].time <= q) {
                int s = v[right].server;
                if (++cnt[s] == 1) ++active;
                ++right;
            }
            int limit = q - x;
            while (left < m && v[left].time < limit) {
                int s = v[left].server;
                if (--cnt[s] == 0) --active;
                ++left;
            }
            ans[idx] = n - active;
        }
        return ans;
    }
};