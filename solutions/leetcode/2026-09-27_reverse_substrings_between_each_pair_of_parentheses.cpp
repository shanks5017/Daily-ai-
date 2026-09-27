#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        vector<string> stk;
        string cur;
        for (char c : s) {
            if (c == '(') {
                stk.push_back(cur);
                cur.clear();
            } else if (c == ')') {
                reverse(cur.begin(), cur.end());
                cur = stk.back() + cur;
                stk.pop_back();
            } else {
                cur.push_back(c);
            }
        }
        return cur;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    if (!(cin >> s)) return 0;
    Solution sol;
    cout << sol.reverseParentheses(s);
    return 0;
}