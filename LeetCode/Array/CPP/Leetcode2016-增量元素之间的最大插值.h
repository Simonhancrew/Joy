#include <vector>
#include <algorithm>

using namespace std;

/*
    前缀最小值，一定是右侧的元素减去左侧最小
    前提是左侧最小一定是小于右侧的元素的
*/

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans = -1,mn = nums[0],n = nums.size();
        for(int i = 1;i < n;i++) {
            if(nums[i] > mn) {
                ans = max(ans,nums[i] - mn);
            }else{
                mn = nums[i];
            }
        }
        return ans;
    }
};