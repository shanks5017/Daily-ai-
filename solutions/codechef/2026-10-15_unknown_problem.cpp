#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    if(!(cin >> N)) return 0;
    int even = 0, odd = 0;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (x % 2 == 0) ++even;
        else ++odd;
    }
    if (even > odd) cout << "READY FOR BATTLE";
    else cout << "NOT READY";
    return 0;
}