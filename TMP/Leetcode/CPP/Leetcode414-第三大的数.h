#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int cnt = 0;
        int64_t f1 = LLONG_MIN,f2 = LLONG_MIN,f3 = LLONG_MIN;
        for(auto x : nums){
            if(x > f3) cnt++,f1 = f2,f2 = f3,f3 = x;
            else if(x < f3 && x > f2) cnt++,f1 = f2,f2 = x;
            else if(x < f2 && x > f1) cnt++,f1 = x;
        }
        if(cnt < 3) return f3;
        return f1;
    }
};