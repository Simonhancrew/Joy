class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int idx = max_element(nums.begin(),nums.end()) - nums.begin();
        int target = nums[idx];    
        for(auto num : nums){
            if(num == target || num == 0) continue;
            if(target / num < 2) return -1;
        }
        return idx;
    }
};