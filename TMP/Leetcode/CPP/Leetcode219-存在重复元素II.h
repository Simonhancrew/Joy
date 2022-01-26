/*
    sliding window和单调队列的写法十分类似
    for range:
        if 头部过期： pop
        check
        更新

*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;
        int n = nums.size();
        for(int i = 0;i < n;i++) {
            if(i > k) st.erase(nums[i - k - 1]);
            if(st.count(nums[i])) return true;
            st.insert(nums[i]);
        }
        return false;
    }
};