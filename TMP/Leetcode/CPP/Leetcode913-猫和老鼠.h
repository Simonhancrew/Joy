#include <vector>
#include <cstring>

using namespace std;

const int N = 55;
int f[2 * N][N][N];
class Solution {
public:
    int n;
    vector<vector<int>> g;
    // 记忆化搜索return的时候记得更新状态
    int dp(int k,int i,int j){
        int &v = f[k][i][j];
        if(v != -1) return v;
        if(k > 2 * n) return v = 0;
        if(!i) return v = 1;
        if(i == j) return v = 2;
        if(k % 2 == 0) { // 老鼠移动，贪心记录，能赢则赢，不能赢尽量平
            int draws = 0;
            for(auto& x : g[i]){
                int t = dp(k + 1,x,j);
                if(t == 1) return v = 1;
                if(t == 0) draws++;
            }
            if(draws) return v = 0;
            return v = 2;
        }else{ // 注意猫不能进洞特判掉
            int draws = 0;
            for(auto& x : g[j]){
                if(x==0) continue;
                int t = dp(k + 1,i,x);
                if(t == 2) return v = 2;
                if(t == 0) draws++;
            }
            if(draws) return v = 0;
            return v = 1;
        }
    }
    int catMouseGame(vector<vector<int>>& graph) {
        memset(f,-1,sizeof f);
        g = graph;
        n = graph.size();
        return dp(0,1,2);
    }
};