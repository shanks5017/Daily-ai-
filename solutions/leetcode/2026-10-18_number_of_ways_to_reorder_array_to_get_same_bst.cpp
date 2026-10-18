#include <bits/stdc++.h>
using namespace std;

const int MOD = 1'000'000'007;

long long modpow(long long a, long long e) {
    long long r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

vector<long long> fact, invFact;

long long C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

pair<int,long long> solve(const vector<int>& arr) {
    int n = arr.size();
    if (n <= 2) return {n, 1LL};
    int root = arr[0];
    vector<int> left, right;
    left.reserve(n);
    right.reserve(n);
    for (int i = 1; i < n; ++i) {
        if (arr[i] < root) left.push_back(arr[i]);
        else right.push_back(arr[i]);
    }
    auto leftRes = solve(left);
    auto rightRes = solve(right);
    int lsz = leftRes.first, rsz = rightRes.first;
    long long ways = C(lsz + rsz, lsz);
    ways = ways * leftRes.second % MOD;
    ways = ways * rightRes.second % MOD;
    return {n, ways};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> nums;
    int x;
    // Read input as a list like [2,1,3] or space separated numbers
    string line;
    if (!getline(cin, line)) return 0;
    // Remove brackets and commas
    for (char &c : line) {
        if (c == '[' || c == ']' || c == ',') c = ' ';
    }
    stringstream ss(line);
    while (ss >> x) nums.push_back(x);
    int n = nums.size();
    fact.resize(n + 1);
    invFact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i % MOD;
    invFact[n] = modpow(fact[n], MOD - 2);
    for (int i = n; i > 0; --i) invFact[i - 1] = invFact[i] * i % MOD;
    long long totalWays = solve(nums).second;
    long long ans = (totalWays - 1 + MOD) % MOD;
    cout << ans << "\n";
    return 0;
}