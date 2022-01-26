#include <vector>

using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i < n;i++){
            if(i == 0) continue;
            nums[i] += nums[i - 1];
        }
        return nums;
    }
};