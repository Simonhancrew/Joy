#include <cstring>
#include <algorithm>

using namespace std;


#if 0
// dp[i]，形成i个A需要多少步，当前i一定是有i的约数转移而来的，只需要枚举i的约数就可以了
// 同理，n一定是由n的约数转移过来的，只需要枚举n的约数状态就可以了
class Solution {
public:
    int minSteps(int n) {
        int dp[n + 1];
        memset(dp,0x3f,sizeof dp);
        dp[1] = 0;
        for(int i = 2;i <= n;i++){
            if(n % i != 0) continue;
            for(int j = 1;j * j <= i;j++){
                if(i % j != 0) continue;
                dp[i] = min(dp[i],dp[j] + i / j);
                dp[i] = min(dp[i],dp[i / j] + j);
            }
        }
        return dp[n];
    }
};
#endif

// 一定是一个全部的质因数之和，就是一个简单的分解质因数的模板
class Solution {
public:
    int minSteps(int n) {
        int res = 0;
        for(int i = 2;i <= n / i;i++){
            while(n % i == 0){
                res += i;
                n /= i;
            }
        }
        // cout << n << endl;
        if(n > 1) res += n;
        return res;
    }
};