#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        const int INF = 1e9;
        vector<int> first(26, INF), last(26, -1);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = max(last[c], i);
        }
        vector<pair<int,int>> intervals;
        for (int c = 0; c < 26; ++c) {
            if (first[c] == INF) continue;
            int l = first[c], r = last[c];
            bool changed = true;
            while (changed) {
                changed = false;
                for (int i = l; i <= r; ++i) {
                    int ch = s[i] - 'a';
                    if (first[ch] < l) {
                        l = first[ch];
                        changed = true;
                    }
                    if (last[ch] > r) {
                        r = last[ch];
                        changed = true;
                    }
                }
            }
            if (l == first[c]) intervals.emplace_back(l, r);
        }
        sort(intervals.begin(), intervals.end(),
             [](const pair<int,int>& a, const pair<int,int>& b){
                 return a.second < b.second;
             });
        vector<string> ans;
        int prev_end = -1;
        for (auto &p : intervals) {
            if (p.first > prev_end) {
                ans.push_back(s.substr(p.first, p.second - p.first + 1));
                prev_end = p.second;
            }
        }
        return ans;
    }
};