class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> st;
        int ans = -1, n = nums.size();
        for (int i = 0;i < n;i++) {
            st.insert(nums[i]);
            if (nums[i] && st.count(-nums[i])) {
                ans = max(ans, abs(nums[i]));
            }
        }   
        return ans;
    }
};

