#include <string>
#include <vector>

using namespace std;


// 前i位有多少种解码的方式，对于最后一位，枚举26个数，看看能不能匹配，能的话就考虑加上方案数

class Solution {
public:
    const int MOD = 1e9 + 7;
    typedef long long LL;
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        for(int i = 1;i <= n;i++){
            // 枚举每 一or两 位所有能匹配到的情况
            for(int j = 1;j <= 26;j++){
                if(j <= 9){
                    if(s[i - 1] == '*' || s[i - 1] == j + '0') dp[i] = (LL)(dp[i] + dp[i - 1]) % MOD;
                }else if(i >= 2){
                    int x = j / 10,y = j % 10;//个位，十位
                    if((s[i - 2] == x + '0' || s[i - 2] == '*' && x) && (s[i - 1] == y + '0' || s[i - 1] == '*' && y)) dp[i] = (LL) (dp[i] + dp[i - 2]) % MOD;
                }
            }
        }
        return dp[n];
    }
};