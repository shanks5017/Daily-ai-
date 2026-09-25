#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        long long P, Q;
        cin >> P >> Q;
        long long total = P + Q;
        long long block = total / 2; // (total)/2 equals (s-1)/2 where s = total+1
        if (block % 2 == 0)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
    return 0;
}