#include <vector>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int res = 0,last = -1;
        for(auto x : timeSeries){
            int t = x + duration - 1;
            res += last < x ? duration : t - last;
            last = t;
        }
        return res;
    }
};