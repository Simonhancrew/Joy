class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n =  nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        int acc = 0;
        vector<int> ans;
        for(int i = n - 1;i >= 0 && acc <= sum;i--) {
            acc += nums[i],sum -= nums[i];
            ans.push_back(nums[i]);
        }
        return ans;
    }
};
