#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string s;
    int n;
    int pos;
    
    unordered_set<string> parseExpression() {
        unordered_set<string> cur;
        cur.insert("");
        while (pos < n && s[pos] != '}' && s[pos] != ',') {
            unordered_set<string> factor = parseFactor();
            unordered_set<string> next;
            for (const string& a : cur) {
                for (const string& b : factor) {
                    next.insert(a + b);
                }
            }
            cur.swap(next);
        }
        return cur;
    }
    
    unordered_set<string> parseFactor() {
        if (s[pos] == '{') {
            return parseUnion();
        } else { // letter
            unordered_set<string> res;
            res.insert(string(1, s[pos]));
            ++pos;
            return res;
        }
    }
    
    unordered_set<string> parseUnion() {
        // assume s[pos] == '{'
        ++pos; // skip '{'
        unordered_set<string> result;
        while (true) {
            unordered_set<string> exprSet = parseExpression();
            result.insert(exprSet.begin(), exprSet.end());
            if (pos < n && s[pos] == ',') {
                ++pos; // skip ','
                continue;
            }
            if (pos < n && s[pos] == '}') {
                ++pos; // skip '}'
                break;
            }
        }
        return result;
    }
    
    vector<string> braceExpansionII(string expression) {
        s = expression;
        n = s.size();
        pos = 0;
        unordered_set<string> ansSet = parseExpression();
        vector<string> ans(ansSet.begin(), ansSet.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};