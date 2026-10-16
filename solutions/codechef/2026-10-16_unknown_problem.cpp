#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        long long X;
        cin >> X;
        long long discount = 0;
        if (X <= 100) discount = 0;
        else if (X <= 1000) discount = 25;
        else if (X <= 5000) discount = 100;
        else discount = 500;
        cout << (X - discount) << "\n";
    }
    return 0;
}