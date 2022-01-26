#include <vector>

using namespace std;

// 数位dp，先预处理，再按位判断

class Solution {
public:
    int findIntegers(int n) {
        vector<int> num;
        while(n) num.push_back(n & 1),n >>= 1;
        int dp[32][2];
        memset(dp,0,sizeof dp);
        dp[1][0] = 1,dp[1][1] = 1;
        for(int i = 2;i <= num.size();i++){
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][1] = dp[i - 1][0];
        }

        int res = 0;
        for(int i = num.size(),last = 0;i;i--){
            if(num[i - 1]){
                res += dp[i][0];
                // 要找比n小的合法情况，此时连续1出现，情况结束
                if(last) return res;
            }
            last = num[i - 1];
        }
        return res + 1;
    }
};