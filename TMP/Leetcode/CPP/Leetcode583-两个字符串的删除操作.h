#include <string>
#include <vector>
using namespace std;
#if 0
//删除的结果就是最长公共子序列，可以从以上地推过来
class Solution {
public:
    int minDistance(string &word1, string &word2) {
        int lcs = longestCommonSubsequence(word1,word2);
        int m = word1.size(),n =word2.size();
        return m+n-2*lcs; 
    }
private:
    int longestCommonSubsequence(string &text1, string &text2) {
        int m = text1.size(),n = text2.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1));
        for(int i =1;i <= m;++i){
            for(int j = 1;j <= n;++j){
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[m][n];
    }
};
#endif

// 这不就是简化版的edit distance嘛
// dp[i][j],a的前i个字符变成b的前j个字符要删除多少个
/* 
    分4种情况：
    1. a[i],b[j]都要删除
    2. a[i],b[j]留i
    3. 留j
    4. 都留
    都留的情况其实在前两者种已经覆盖到了（又可以继续细分），不必单独考虑了。
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(),m = word2.size();
        int dp[n + 1][m + 1];
        memset(dp,0,sizeof dp);
        for(int i = 0;i <= n;i++) dp[i][0] = i;
        for(int i = 0;i <= m;i++) dp[0][i] = i;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m;j++){
                dp[i][j] = min(dp[i - 1][j] + 1,dp[i][j - 1] + 1);
                if(word1[i - 1] == word2[j - 1]) dp[i][j] = min(dp[i][j],dp[i - 1][j - 1]);
            }
        }
        return dp[n][m];
    }
};