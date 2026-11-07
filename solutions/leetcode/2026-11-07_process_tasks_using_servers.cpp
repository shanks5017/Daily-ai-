#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size(), m = tasks.size();
        vector<int> ans(m);
        using FreeItem = pair<long long,int>; // weight, index
        using BusyItem = tuple<long long,long long,int>; // free_time, weight, index
        priority_queue<FreeItem, vector<FreeItem>, greater<FreeItem>> freePQ;
        priority_queue<BusyItem, vector<BusyItem>, greater<BusyItem>> busyPQ;
        for (int i = 0; i < n; ++i) freePQ.emplace(servers[i], i);
        long long cur = 0;
        for (int i = 0; i < m; ++i) {
            cur = max<long long>(cur, i);
            while (!busyPQ.empty() && get<0>(busyPQ.top()) <= cur) {
                auto [t,w,idx] = busyPQ.top(); busyPQ.pop();
                freePQ.emplace(w, idx);
            }
            if (freePQ.empty()) {
                auto [t,w,idx] = busyPQ.top(); busyPQ.pop();
                cur = t;
                freePQ.emplace(w, idx);
                while (!busyPQ.empty() && get<0>(busyPQ.top()) == cur) {
                    auto [t2,w2,idx2] = busyPQ.top(); busyPQ.pop();
                    freePQ.emplace(w2, idx2);
                }
            }
            auto [w, idx] = freePQ.top(); freePQ.pop();
            ans[i] = idx;
            busyPQ.emplace(cur + tasks[i], w, idx);
        }
        return ans;
    }
};