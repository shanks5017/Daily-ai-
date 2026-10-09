#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        long long ans = 0;
        long long need = 0; // number of ')' needed
        for (char c : s) {
            if (c == '(') {
                need += 2;
                if (need % 2 == 1) { // if need is odd, we have an extra ')'
                    // insert one ')' to balance previous '('
                    ans++;
                    need--; // now need becomes even
                }
            } else { // c == ')'
                need--;
                if (need == -1) {
                    // need a '(' before this ')'
                    ans++;
                    need = 1; // after inserting '(', we still need one more ')'
                }
            }
        }
        ans += need;
        return (int)ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    if (!(cin >> s)) return 0;
    Solution sol;
    cout << sol.minInsertions(s);
    return 0;
}