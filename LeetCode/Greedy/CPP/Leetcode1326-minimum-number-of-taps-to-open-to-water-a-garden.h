#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        using PII = pair<int, int>;
        vector<PII> rec;
        for (int i = 0;i < ranges.size();i++) {
            rec.emplace_back(i - ranges[i], i + ranges[i]);
        }
        sort(rec.begin(), rec.end());
        int res = 0, r = 0;
        for (int i = 0;i < rec.size();i++) {
            int j = i, mr = -1;
            while (j < rec.size() && rec[j].first <= r) mr = max(mr, rec[j++].second);
            if (mr == -1) return -1;
            res++;
            if (mr >= n) return res;
            r = mr;
            i = j - 1;
        }
        return -1;
    }
};
