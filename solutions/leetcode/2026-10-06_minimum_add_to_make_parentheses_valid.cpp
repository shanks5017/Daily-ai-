#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int need = 0, balance = 0;
        for (char c : s) {
            if (c == '(') {
                ++balance;
            } else {
                if (balance > 0) {
                    --balance;
                } else {
                    ++need;
                }
            }
        }
        return need + balance;
    }
};