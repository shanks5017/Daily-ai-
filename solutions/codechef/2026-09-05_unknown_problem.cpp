#include <bits/stdc++.h>
using namespace std;

string multiply(const string &num, int mul) {
    if (mul == 0) return "0";
    string res;
    int carry = 0;
    for (int i = (int)num.size() - 1; i >= 0; --i) {
        int prod = (num[i] - '0') * mul + carry;
        res.push_back(char('0' + (prod % 10)));
        carry = prod / 10;
    }
    while (carry) {
        res.push_back(char('0' + (carry % 10)));
        carry /= 10;
    }
    while (res.size() > 1 && res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin>>t)) return 0;
    vector<int> queries(t);
    int maxn = 0;
    for(int i=0;i<t;++i){
        cin>>queries[i];
        maxn = max(maxn, queries[i]);
    }
    vector<string> fact(maxn+1);
    fact[0] = "1";
    for(int i=1;i<=maxn;++i){
        fact[i] = multiply(fact[i-1], i);
    }
    for(int n: queries){
        cout<<fact[n]<<"\n";
    }
    return 0;
}