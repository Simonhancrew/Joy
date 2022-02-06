class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int st[101] = {0},ans = 0;
        for(int i = 0;i < nums.size();i++) st[nums[i]]++;
        for(int i = 1;i <= 100;i++) if(st[i] == 1) ans += i;
        return ans;
    }
};