class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans = 1,acc = 0;
        for(int i = 0;i < nums.size();i++) {
            acc += nums[i];
            int nag = 1 - acc;
            if(ans < nag) ans = nag;
        }
        return ans;
    }
};
