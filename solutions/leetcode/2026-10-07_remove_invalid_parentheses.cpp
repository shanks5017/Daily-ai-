#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left_rem = 0, right_rem = 0;
        for (char c : s) {
            if (c == '(') {
                left_rem++;
            } else if (c == ')') {
                if (left_rem > 0) left_rem--;
                else right_rem++;
            }
        }
        unordered_set<string> result_set;
        string path;
        function<void(int,int,int,int)> dfs = [&](int idx, int lrem, int rrem, int open) {
            if (idx == (int)s.size()) {
                if (lrem == 0 && rrem == 0 && open == 0) {
                    result_set.insert(path);
                }
                return;
            }
            char c = s[idx];
            if (c == '(') {
                if (lrem > 0) {
                    dfs(idx + 1, lrem - 1, rrem, open); // skip
                }
                path.push_back(c);
                dfs(idx + 1, lrem, rrem, open + 1); // keep
                path.pop_back();
            } else if (c == ')') {
                if (rrem > 0) {
                    dfs(idx + 1, lrem, rrem - 1, open); // skip
                }
                if (open > 0) {
                    path.push_back(c);
                    dfs(idx + 1, lrem, rrem, open - 1); // keep
                    path.pop_back();
                }
            } else {
                path.push_back(c);
                dfs(idx + 1, lrem, rrem, open);
                path.pop_back();
            }
        };
        dfs(0, left_rem, right_rem, 0);
        return vector<string>(result_set.begin(), result_set.end());
    }
};