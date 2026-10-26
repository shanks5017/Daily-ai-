#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while (T--) {
        long long a,b,c;
        cin >> a >> b >> c;
        long long x = max(min(a,b), min(max(a,b), c));
        // Alternative robust method: sort three values
        // but using simple approach:
        // Let's just sort using array
        long long arr[3] = {a,b,c};
        sort(arr, arr+3);
        cout << arr[1] << '\n';
    }
    return 0;
}