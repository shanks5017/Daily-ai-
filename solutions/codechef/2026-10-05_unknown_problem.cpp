#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(!(cin >> t)) return 0;
    vector<int> queries(t);
    int max_n = 0;
    for(int i = 0; i < t; ++i){
        cin >> queries[i];
        if(queries[i] > max_n) max_n = queries[i];
    }
    vector<cpp_int> fact(max_n + 1);
    fact[0] = 1;
    for(int i = 1; i <= max_n; ++i){
        fact[i] = fact[i-1] * i;
    }
    for(int n : queries){
        cout << fact[n] << '\n';
    }
    return 0;
}