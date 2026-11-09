#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        vector<int> cnt(k, 0);
        set<int> freeServers;
        for (int i = 0; i < k; ++i) freeServers.insert(i);
        using P = pair<long long, int>;
        priority_queue<P, vector<P>, greater<P>> busy; // (finishTime, serverId)
        int n = arrival.size();
        for (int i = 0; i < n; ++i) {
            long long cur = arrival[i];
            while (!busy.empty() && busy.top().first <= cur) {
                freeServers.insert(busy.top().second);
                busy.pop();
            }
            if (freeServers.empty()) continue;
            int target = i % k;
            auto it = freeServers.lower_bound(target);
            if (it == freeServers.end()) it = freeServers.begin();
            int server = *it;
            cnt[server]++;
            busy.emplace(cur + load[i], server);
            freeServers.erase(it);
        }
        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> res;
        for (int i = 0; i < k; ++i) if (cnt[i] == mx) res.push_back(i);
        return res;
    }
};