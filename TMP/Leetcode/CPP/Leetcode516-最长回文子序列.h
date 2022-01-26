// 区间dp
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        int dp[n][n];
        memset(dp,0,sizeof dp);
        for(int len = 1;len <=n;len++){
            for(int i = 0;i + len - 1 < n;i++){
                int j = i + len - 1;
                if(len == 1) dp[i][j] = 1;
                else{
                    if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
                    dp[i][j] = max(dp[i][j],max(dp[i + 1][j],dp[i][j - 1]));
                }
            }
        }
        return dp[0][n - 1];
    }
};