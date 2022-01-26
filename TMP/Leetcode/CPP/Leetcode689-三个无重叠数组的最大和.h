class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> s(n + 1);
        vector<vector<int>> f(n + 1,vector<int> (4,INT_MIN));
        reverse(nums.begin(),nums.end());
        for(int i = 1;i <= n;i++) s[i] = s[i - 1] + nums[i - 1];
        for(int i = k;i <= n;i++){
            for(int j = 1;j <= 3;j++){
                f[i][j] = max(f[i - 1][j],f[i - k][j - 1] + s[i] - s[i - k]);
            }
        }
        int x = n,y = 3;
        vector<int> res;
        while(y){
            if(f[x - 1][y] > f[x - k][y - 1] + s[x] - s[x - k]) x--;
            else{
                res.push_back(n - x);
                x -= k;
                y--;
            }   
        }
        return res;
    }
};