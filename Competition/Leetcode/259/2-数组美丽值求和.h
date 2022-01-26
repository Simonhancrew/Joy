class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size(),res = 0;
        vector<int> lhs(nums.size()),rhs(nums.size());
        lhs[0] = nums[0],rhs[n - 1] = nums[n - 1];
        for(int i = 1;i < n;i++){
            lhs[i] = max(lhs[i - 1],nums[i]);
        }
        for(int i = n - 2;i >= 0;i--){
            rhs[i] = min(rhs[i + 1],nums[i]);
        }
        for(int i = 1;i <= n - 2;i++){
            if(nums[i] > lhs[i - 1] && nums[i] < rhs[i + 1]){
                res += 2;
            }else if(nums[i] > nums[i - 1] && nums[i] < nums[i + 1]) res += 1;
        }
        return res;
    }
};