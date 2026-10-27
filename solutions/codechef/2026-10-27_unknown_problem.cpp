#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if (!(cin >> N)) return 0;
    long long cum1 = 0, cum2 = 0;
    int bestWinner = 0;
    long long bestLead = 0;
    for (int i = 0; i < N; ++i) {
        long long s, t;
        cin >> s >> t;
        cum1 += s;
        cum2 += t;
        long long diff = cum1 - cum2;
        int winner = diff > 0 ? 1 : 2;
        long long lead = llabs(diff);
        if (lead > bestLead) {
            bestLead = lead;
            bestWinner = winner;
        }
    }
    cout << bestWinner << ' ' << bestLead << '\n';
    return 0;
}