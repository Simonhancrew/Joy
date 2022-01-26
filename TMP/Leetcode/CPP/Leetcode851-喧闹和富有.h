#include <vector>

using namespace std;

/*
    题目保证一个有向无环图，等价于找到他后继里面的最小取到的安静值
    直接记忆化搜索就可以了
    记忆化搜索的模板
    ans = [-1] * n
    def dfs(u):
        if ans[u] != -1: return
        init(ans[u])
        for v in graph[u]:
            dfs(v)
            if ans[u] is upgradeble:
                update(u)
*/
class Solution {
public:
    vector<vector<int>> g;
    vector<int> ans,w;
    void dfs(int u) {
        if(ans[u] != -1) return;
        ans[u] = u;
        for(auto v : g[u]) {
            dfs(v);
            if(w[ans[u]] > w[ans[v]]) {
                ans[u] = ans[v];
            }
        }
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        w = quiet;
        g.resize(n);
        ans.resize(n,-1);
        for(auto rich : richer) {
            int a = rich[0],b = rich[1];
            g[b].push_back(a);
        }
        for(int i = 0;i < n;i++) dfs(i);
        return ans;
    }
};