#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeUniformParity(vector<int>& nums1) {
        if (nums1.empty()) return true;
        sort(nums1.begin(), nums1.end());
        int target = nums1[0] & 1; // parity of minimum element
        bool seen[2] = {false, false};
        seen[target] = true;
        for (size_t i = 1; i < nums1.size(); ++i) {
            int p = nums1[i] & 1;
            if (p != target) {
                int needed = p ^ target; // parity of smaller element required
                if (!seen[needed]) return false;
            }
            seen[p] = true;
        }
        return true;
    }
};