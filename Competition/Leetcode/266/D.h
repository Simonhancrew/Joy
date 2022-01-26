#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mx,n;
    vector<int> visited;
    int res;
    typedef pair<int,int> PII;
    #define x first
    #define y second
    vector<int> values;
    vector<vector<PII>> matrix;
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        mx = maxTime,n = values.size();
        res = 0;
        this->values = values;
        matrix = vector<vector<PII>> (n,vector<PII>());
        for(auto edge : edges){
            int a = edge[0],b = edge[1],c = edge[2];
            matrix[a].push_back({b,c});
            matrix[b].push_back({a,c});
        }
        visited = vector<int> (n,0);
        dfs(0,0,0);
        return res;
    }
    void dfs(int node,int value,int time){
        if(time > mx) return;
        visited[node] += 1;
        if(visited[node] == 1) value += values[node];
        if(node == 0) res = max(value,res);
        for(auto edge : matrix[node]){
            int ne = edge.x,c = edge.y;
            dfs(ne,value,time + c);
        }
        visited[node] -= 1;
    }
};