#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxlen = 0;
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (!st.empty()) st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    maxlen = max(maxlen, i - st.top());
                }
            }
        }
        return maxlen;
    }
};