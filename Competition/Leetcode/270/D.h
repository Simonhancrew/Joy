#include <map>
#include <vector>

using namespace std;

#if 0
// 欧拉图不会，补题
#endif 
/* 
    对于欧拉图，从哪一点开始搜都可以;对于半欧拉图就要从起点开始搜了;
    这里是一个有向图，直接记录度数就可以了
    然后实际搜的时候考虑回溯的问题，需要做一个删除用过的边的步骤
    vector天然可以考虑倒叙遍历，删除最后的节点。记得取引用，不然是值语义，直接复制了。
    参考了提高课欧拉路径的优化
*/
class Solution {
public:
    map<int,vector<int>> g;
    map<int,int> deg;
    vector<vector<int>> ans;

    void dfs(int u){
        auto &e = g[u];
        while(e.size()){
            int t = e.back();
            e.pop_back();
            dfs(t);
            ans.push_back({u,t});
        } 
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        for(auto &pair : pairs) {
            g[pair[0]].push_back(pair[1]);
            deg[pair[0]]--,deg[pair[1]]++;
        }    
        for(auto it = deg.begin();it != deg.end();it++) if(it->second == -1) dfs(it->first);
        if(ans.empty()) dfs(deg.begin()->first);
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};