#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& g) {
        int m = g.size(),n = g[0].size();
        vector<vector<int>> res;
        // 直接更改原数组记录就可以
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(g[i][j]){
                    int a = i,b = j;
                    for(int x = i;x < m && g[x][j];x++){
                        for(int y = j;y < n && g[x][y];y++){
                            g[x][y] = 0;
                            a = max(a,x),b = max(b,y);
                        }
                    }
                    res.push_back({i,j,a,b});
                }
            }
        }
        return res;
    }
};