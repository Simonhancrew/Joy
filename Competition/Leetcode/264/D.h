#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 拓扑 + dp
// dp[i]，完成任务当前节点最少需要多久
// dp[i] = max(dp[pre]) + time[cur]

class Solution {
public:
    vector<int> in;
    int minimumTime(int n, vector<vector<int>>& re, vector<int>& time) {
        in.resize(n + 1);
        vector<vector<int>> g(n + 1);
        for(auto r : re){
            in[r[1]]++;
            g[r[0]].push_back(r[1]);
        }
        queue<int> q;
        for(int i = 1;i <= n;i++){
            if(in[i] == 0) q.push(i);
        }
        vector<int> dp(n + 1);
        while(q.size()){
            auto t = q.front();q.pop();
            dp[t] += time[t - 1];
            for(auto v : g[t]){
                in[v]--;
                if(in[v] == 0) {
                    q.push(v);
                }
                dp[v] = max(dp[t],dp[v]);
            }
        }
        return *max_element(dp.begin() + 1,dp.end());
    }
};