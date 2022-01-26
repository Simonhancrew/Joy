#include <vector>

using namespace std;

// 大模拟，找到每个人的友好级别，遍历所有的不同pair，看看是否有不开心的x或者y

class Solution {
public:
    vector<vector<int>> rank;
    bool check(int x,int y,int u,int v){
        return rank[x][u] < rank[x][y] && rank[u][x] < rank[u][v]; 
    }
    int unhappyFriends(int n, vector<vector<int>>& preferences, vector<vector<int>>& pairs) {
        int ans = 0;
        rank = vector<vector<int>> (n,vector<int>(n));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n - 1;j++){
                rank[i][preferences[i][j]] = j;
            }
        }
        for(int i = 0;i < pairs.size();i++){
            int x = pairs[i][0],y = pairs[i][1];
            bool unha_x = false,unha_y = false;
            for(int j = 0;j < pairs.size();j++){
                if(i == j) continue;
                int u = pairs[j][0],v = pairs[j][1];
                if(!unha_x && (check(x,y,u,v) || check(x,y,v,u))){
                    unha_x = true;
                    ans++;
                }
                if(!unha_y && (check(y,x,u,v) || check(y,x,v,u))){
                    unha_y = true;
                    ans++;
                }
                if(unha_x && unha_y) break;
            }
        }
        return ans;
    }
};