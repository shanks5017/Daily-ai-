#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low = max(low - 1, 0);
                high--;
            } else { // '*'
                low = max(low - 1, 0); // treat as ')'
                high++;               // treat as '('
            }
            if (high < 0) return false;
        }
        return low == 0;
    }
};