#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> cur;
        dfs(0,cur,graph);
        return res;
    }
    void dfs(int idx,vector<int> &cur,vector<vector<int>>& graph){
        int n = graph.size();
        if(idx == n){
            return;
        }
        cur.push_back(idx);
        if(idx == n - 1) {
            res.push_back(cur);
            return;
        }
        for(auto node:graph[idx]){
            dfs(node,cur,graph);
            cur.pop_back();
        }
    }
};