class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector<int> lmx(n, INT_MIN), rmn(n, INT_MAX);
        lmx[0] = nums[0], rmn[n - 1] = nums[n - 1];
        for(int i = 1;i < n;i++) {
            lmx[i] = max(lmx[i - 1], nums[i]);
        }
        for(int i = n - 2;i >= 0;i--) {
            rmn[i] = min(rmn[i + 1], nums[i]);
        }
        int ans = 1;
        for(int i = 0;i < n - 1;i++) {
            if(lmx[i] <= rmn[i + 1]) break;
            ans++;
        }
        return ans;
    }
};
