#include <string>

using namespace std;

// 参考0x3f的题解

class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberOfUniqueGoodSubsequences(string binary) {
        int dp[2];
        memset(dp,0,sizeof dp);
        for(int i = binary.size() - 1;i >= 0;i--){
            dp[binary[i] & 1] = (dp[0] + dp[1] + 1) % MOD;
        }
        int ans = dp[1];
        if(binary.find("0") != string::npos){
            ans = (ans + 1) % MOD;
        }
        return ans;
    }
};