class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int n = flips.size(), res = 0, r = 0;
        for (int i = 1;i <= n;i++) {
            int idx = flips[i - 1];
            r = max(r, idx);
            if (r == i) ++res;
        }
        return res;
    }
};


