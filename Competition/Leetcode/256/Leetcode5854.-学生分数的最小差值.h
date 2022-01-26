#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if(k == 1) return 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int res = INT_MAX;
        for(int i = 0;i <= n - k;i++){
            res = min(res,nums[i + k - 1] - nums[i]);
        }
        return res;
    }
};