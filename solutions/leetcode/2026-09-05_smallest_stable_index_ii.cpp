#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string line;
    if (!getline(cin, line)) return 0;
    vector<long long> nums;
    string cur;
    for (char c : line) {
        if (isdigit(c) || c == '-') cur += c;
        else {
            if (!cur.empty()) {
                nums.push_back(stoll(cur));
                cur.clear();
            }
        }
    }
    if (!cur.empty()) {
        nums.push_back(stoll(cur));
        cur.clear();
    }
    long long k;
    if (!(cin >> k)) {
        string kline;
        if (getline(cin, kline)) {
            stringstream ss(kline);
            ss >> k;
        }
    }
    int n = nums.size();
    if (n == 0) {
        cout << -1;
        return 0;
    }
    vector<long long> pref(n), suff(n);
    for (int i = 0; i < n; ++i) {
        pref[i] = (i == 0) ? nums[i] : max(pref[i - 1], nums[i]);
    }
    for (int i = n - 1; i >= 0; --i) {
        suff[i] = (i == n - 1) ? nums[i] : min(suff[i + 1], nums[i]);
    }
    int ans = -1;
    for (int i = 0; i < n; ++i) {
        if (pref[i] - suff[i] <= k) {
            ans = i;
            break;
        }
    }
    cout << ans;
    return 0;
}