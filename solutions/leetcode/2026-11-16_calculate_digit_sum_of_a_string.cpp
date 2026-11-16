#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > (size_t)k) {
            string ns;
            for (size_t i = 0; i < s.size(); i += k) {
                int sum = 0;
                for (size_t j = i; j < i + (size_t)k && j < s.size(); ++j) {
                    sum += s[j] - '0';
                }
                ns += to_string(sum);
            }
            s.swap(ns);
        }
        return s;
    }
};