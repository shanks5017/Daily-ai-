#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct State {
        long long w = 0;
        int sz = 0;
        int ids[4];
        State() : w(0), sz(0) {}
    };
    
    // return true if a is better than b
    static bool better(const State& a, const State& b) {
        if (a.w != b.w) return a.w > b.w;
        int m = min(a.sz, b.sz);
        for (int i = 0; i < m; ++i) {
            if (a.ids[i] != b.ids[i]) return a.ids[i] < b.ids[i];
        }
        return a.sz < b.sz;
    }
    
    vector<int> maxScoreIndices(vector<vector<int>>& intervals) {
        int n = intervals.size();
        struct Interval {
            int l, r;
            long long w;
            int idx;
        };
        vector<Interval> a;
        a.reserve(n);
        for (int i = 0; i < n; ++i) {
            a.push_back({intervals[i][0], intervals[i][1], intervals[i][2], i});
        }
        sort(a.begin(), a.end(), [](const Interval& x, const Interval& y){
            if (x.r != y.r) return x.r < y.r;
            return x.l < y.l;
        });
        vector<int> ends(n+1);
        ends[0] = -2e9; // dummy
        for (int i = 1; i <= n; ++i) ends[i] = a[i-1].r;
        
        vector<int> p(n+1,0);
        for (int i = 1; i <= n; ++i) {
            int l = a[i-1].l;
            int lo = 1, hi = i-1, ans = 0;
            while (lo <= hi) {
                int mid = (lo+hi)/2;
                if (ends[mid] < l) {
                    ans = mid;
                    lo = mid+1;
                } else hi = mid-1;
            }
            p[i] = ans;
        }
        
        const int K = 4;
        vector<array<State, K+1>> dp(n+1);
        // dp[0][c] already zero
        
        for (int i = 1; i <= n; ++i) {
            for (int c = 0; c <= K; ++c) {
                // not take
                dp[i][c] = dp[i-1][c];
            }
            for (int c = 1; c <= K; ++c) {
                State cand = dp[p[i]][c-1];
                cand.w += a[i-1].w;
                cand.ids[cand.sz] = a[i-1].idx;
                ++cand.sz;
                // insertion sort to keep ids sorted
                for (int t = cand.sz-1; t>0 && cand.ids[t] < cand.ids[t-1]; --t)
                    swap(cand.ids[t], cand.ids[t-1]);
                if (better(cand, dp[i][c])) dp[i][c] = cand;
            }
        }
        State best;
        for (int c = 0; c <= K; ++c) {
            if (better(dp[n][c], best)) best = dp[n][c];
        }
        vector<int> res(best.sz);
        for (int i = 0; i < best.sz; ++i) res[i] = best.ids[i];
        return res;
    }
};