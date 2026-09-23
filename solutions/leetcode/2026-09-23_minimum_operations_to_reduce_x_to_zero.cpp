#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string line;
    if (!getline(cin, line)) return 0;
    // parse array from line
    vector<int> nums;
    for (char &c : line) {
        if (!(isdigit(c) || c == '-' )) c = ' ';
    }
    stringstream ss(line);
    long long val;
    while (ss >> val) nums.push_back((int)val);
    
    // read x
    long long x;
    if (!(cin >> x)) return 0;
    
    int n = nums.size();
    long long total = 0;
    for (int v : nums) total += v;
    
    long long target = total - x;
    if (target < 0) {
        cout << -1;
        return 0;
    }
    if (target == 0) {
        cout << n;
        return 0;
    }
    
    int maxLen = -1;
    long long cur = 0;
    int left = 0;
    for (int right = 0; right < n; ++right) {
        cur += nums[right];
        while (left <= right && cur > target) {
            cur -= nums[left++];
        }
        if (cur == target) {
            maxLen = max(maxLen, right - left + 1);
        }
    }
    
    if (maxLen == -1) cout << -1;
    else cout << (n - maxLen);
    return 0;
}