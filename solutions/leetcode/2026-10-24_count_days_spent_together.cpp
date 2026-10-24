#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dayOfYear(const string& date) {
        static const int mdays[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        int month = stoi(date.substr(0,2));
        int day = stoi(date.substr(3,2));
        int sum = 0;
        for (int m = 1; m < month; ++m) sum += mdays[m];
        sum += day;
        return sum;
    }
    
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int a1 = dayOfYear(arriveAlice);
        int a2 = dayOfYear(leaveAlice);
        int b1 = dayOfYear(arriveBob);
        int b2 = dayOfYear(leaveBob);
        int start = max(a1, b1);
        int end = min(a2, b2);
        return max(0, end - start + 1);
    }
};