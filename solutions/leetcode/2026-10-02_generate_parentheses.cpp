#include <bits/stdc++.h>
using namespace std;

void backtrack(int open, int close, int n, string &cur, vector<string> &res) {
    if ((int)cur.size() == 2 * n) {
        res.push_back(cur);
        return;
    }
    if (open < n) {
        cur.push_back('(');
        backtrack(open + 1, close, n, cur, res);
        cur.pop_back();
    }
    if (close < open) {
        cur.push_back(')');
        backtrack(open, close + 1, n, cur, res);
        cur.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    string cur;
    backtrack(0, 0, n, cur, res);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    bool firstOutput = true;
    while (cin >> n) {
        vector<string> ans = generateParenthesis(n);
        cout << '[';
        for (size_t i = 0; i < ans.size(); ++i) {
            cout << '"' << ans[i] << '"';
            if (i + 1 != ans.size()) cout << ',';
        }
        cout << ']';
        if (!cin.eof()) cout << '\n';
    }
    return 0;
}