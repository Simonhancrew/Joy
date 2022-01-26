#include <vector>

using namespace std;
using ll = long long;

// 带节点数量的dfs

class Solution {
public:
    vector<int> sz;
    int cnt;
    ll mx = 0;
    int n;
    vector<vector<int>> g;
    int countHighestScoreNodes(vector<int>& par) {
        n = par.size();
        g.resize(n);
        for(int i = 1;i < par.size();i++){
            g[par[i]].push_back(i);
        }
        sz.resize(n);
        dfs(0);
        return cnt;
    }
    void dfs(int u){
        sz[u] = 1;
        ll tmp = 1;
        for(auto v : g[u]){
            dfs(v);
            sz[u] += sz[v];
            tmp *= sz[v];
        }
        if(n - sz[u]) tmp *= n - sz[u];
        if(tmp > mx){
            mx = tmp;
            cnt = 1;
        }else if(tmp == mx){
            cnt += 1;
        }
    }
};