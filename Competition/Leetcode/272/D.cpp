/*
    1. 按照k划分成多个区间
    2. 对每个区间求一个LNDS(longest not decrese sequense)
    3. 数据范围1e5，用贪心+2分的方法
    4. st[i]代表长度为i + 1的最长不降序列的结尾最小值是st[i]
*/
class Solution {
public:
    int get(vector<int>& nums){
        vector<int> st;
        for(int i = 0;i < nums.size();i++){
            int cur = nums[i];
            auto it = upper_bound(st.begin(),st.end(),cur);
            if(it == st.end()) st.push_back(cur);
            else *it = cur;
        }
        return st.size();
    }

    int kIncreasing(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0;
        for(int t = 0;t < k;t++){
            vector<int> nums;
            for(int i = t;i < n;i += k){
                nums.push_back(arr[i]);
            }
            ans += get(nums);
        }
        return n - ans;
    }
};