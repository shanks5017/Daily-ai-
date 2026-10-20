#include <bits/stdc++.h>
using namespace std;

bool isRotation(const vector<int>& orig, int a_start,
                const vector<int>& sorted, int b_start, int k) {
    if (k == 1) return orig[a_start] == sorted[b_start];
    // pattern = B (sorted block)
    vector<int> pat(k);
    for (int i = 0; i < k; ++i) pat[i] = sorted[b_start + i];
    // build lps
    vector<int> lps(k, 0);
    for (int i = 1, len = 0; i < k; ) {
        if (pat[i] == pat[len]) {
            lps[i++] = ++len;
        } else if (len) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    // KMP over text = A+A (orig block duplicated)
    int i = 0, j = 0;
    int text_len = 2 * k - 1; // we don't need the last full repeat
    while (i < text_len) {
        int cur = orig[a_start + (i % k)];
        if (cur == pat[j]) {
            ++i; ++j;
            if (j == k) {
                int startPos = i - k;
                if (startPos < k) return true;
                j = lps[j - 1];
            }
        } else if (j) {
            j = lps[j - 1];
        } else {
            ++i;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums;
    int x;
    // Read input as a list like [3,1,2] or space separated numbers
    string line;
    if (!getline(cin, line)) return 0;
    // Remove brackets and commas
    for (char &c : line) {
        if (c == '[' || c == ']' || c == ',') c = ' ';
    }
    stringstream ss(line);
    while (ss >> x) nums.push_back(x);
    int n = nums.size();
    vector<int> sorted = nums;
    sort(sorted.begin(), sorted.end());
    // compute divisors
    vector<int> divisors;
    for (int i = 1; i * (long long)i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) divisors.push_back(n / i);
        }
    }
    long long ans = 0;
    for (int k : divisors) {
        bool ok = true;
        for (int start = 0; start < n; start += k) {
            if (!isRotation(nums, start, sorted, start, k)) {
                ok = false;
                break;
            }
        }
        if (ok) ans += k;
    }
    cout << ans;
    return 0;
}