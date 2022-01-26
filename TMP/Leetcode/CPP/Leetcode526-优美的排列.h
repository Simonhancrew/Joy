#include <cstring>
using namespace std;

// 1 N < 20,考虑dfs和状压dp
// 2 dp[i]，i中的每一个二进制位代表这个数字有没有被用过。
// 先统计当前用了那些数，之后枚举每个数，看看能不能放在下一位置

class Solution {
public:
    int countArrangement(int n) {
        int dp[1 << n];
        memset(dp,0,sizeof dp);
        dp[0] = 1;
        for(int i = 0;i < 1 << n;i++){
            int k = 0;
            for(int j = 0;j < n;j++){
                if(i >> j & 1) k++;
            }
            for(int j = 0;j < n;j++){
                if(!(i >> j & 1)){
                    if((k + 1) % (j + 1) == 0 || (j + 1) % (k + 1) == 0){
                        dp[i | (1 << j)] += dp[i];
                    }
                }
            }
        }

        // c++里面，位移运算符的优先级是低于+和-，但是高于&和|的
        return dp[(1 << n) - 1];
    }
};