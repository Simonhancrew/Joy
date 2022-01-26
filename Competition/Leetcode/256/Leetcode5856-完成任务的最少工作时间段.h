#include <vector>

using namespace std;

// 状压dp

/*

1. 预处理阶段，对于每个状态，能在session内昨晚就记为一个单位时间

2. 枚举阶段，枚举他的所有的子状态，看看能不能更短的做完。

*/

class Solution {
public:
    const int INF = 1e9;
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        vector<int> dp(1 << n,INF);
        for(int i = 1;i < (1 << n);i++){
            int st = i,idx = 0,cost = 0;
            while(st){
                if(st & 1) cost += tasks[idx];
                idx++;
                st >>= 1;
            }
            if(cost <= sessionTime) dp[i] = 1;
        }
        for(int i = 1;i < (1 << n);i++){
            if(dp[i] == 1) continue;
            for(int j = i;j;j = (j -1) & i){
                dp[i] = min(dp[i],dp[j] + dp[i ^ j]);
            }
        }
        return dp[(1 << n) - 1];
    }
};