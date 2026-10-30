#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if(!(cin >> T)) return 0;
    vector<unsigned long long> fact(21,1);
    for(int i=1;i<=20;++i) fact[i]=fact[i-1]*i;
    while(T--) {
        int N;
        cin >> N;
        if(N<0) N=0;
        cout << fact[N];
        if(T) cout << '\n';
    }
    return 0;
}