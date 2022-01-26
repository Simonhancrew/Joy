// dp[i][j][k] 前i中出勤记录中，有j个a，末尾有k个连续的l的出勤记录成立值
// 从前往后，逐渐递推结果、


class Solution {
public:
    const int MOD = 1e9 + 7;
    int checkRecord(int n) {
        int dp[n + 1][2][3];
        memset(dp,0,sizeof dp);
        dp[0][0][0] = 1;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < 2;j++){
                for(int k = 0;k < 3;k++){
                    if(j == 0) dp[i + 1][j + 1][0] = (dp[i + 1][j + 1][0] + dp[i][j][k]) % MOD;
                    if(k < 2) dp[i + 1][j][k + 1] = (dp[i + 1][j][k + 1] + dp[i][j][k])% MOD;
                    dp[i + 1][j][0] = (dp[i + 1][j][0] + dp[i][j][k]) % MOD;
                }
            }
        }
        int res = 0;
        for(int i = 0;i < 2;i++){
            for(int j = 0;j < 3;j++){
                res = (res + dp[n][i][j]) % MOD;
            }
        }
        return res;
    }
};