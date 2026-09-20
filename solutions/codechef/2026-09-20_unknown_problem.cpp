#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        int N;
        cin >> N;
        string deck = (N <= 15) ? "Lower" : "Upper";
        bool isDouble;
        if (deck == "Lower") {
            isDouble = (N <= 10);
        } else {
            isDouble = (N <= 25);
        }
        cout << deck << (isDouble ? " Double" : " Single");
        if (T) cout << '\n';
    }
    return 0;
}