#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

// 思考前面一维接雨水的做法，这种二维的做法对于一个点就是要求其上下左右四个方向上最大值的最小值（木桶短板）
// 然后每一个点的高度就是之前四个方向上的最小值和自身取一个max，雨水的多少就是这个最后高度减去自身实际高度
// 这就可以抽象成是一个建图 + 最短路的问题了，外部看为root，最外面一圈的距离确定，求里面到root的最小距离

class Solution {
public:
    struct cell{
        int x,y,h;
    };
    int trapRainWater(vector<vector<int>>& h) {
        auto cmp = [](cell &lhs,cell &rhs){
            return lhs.h > rhs.h;
        };
        priority_queue<cell,vector<cell>,decltype(cmp)> heap(cmp);
        // 把四周的加入
        int n = h.size(),m = h[0].size();
        vector<vector<int>> st(n,vector<int> (m,0));
        for(int i = 0;i < m;i++){
            heap.push({0,i,h[0][i]}),st[0][i] = 1;
            heap.push({n - 1,i,h[n - 1][i]}),st[n - 1][i] = 1;
        }
        for(int i = 1;i < n - 1;i++){
            heap.push({i,0,h[i][0]}),st[i][0] = 1;
            heap.push({i,m - 1,h[i][m - 1]}),st[i][m - 1] = 1;
        }
        int dx[4] = {0,1,0,-1},dy[4] = {1,0,-1,0};
        int res = 0;
        while(heap.size()){
            auto t = heap.top();
            heap.pop();
            int x = t.x,y = t.y,he = t.h;
            res += he - h[x][y];
            for(int i = 0;i < 4;i++){
                int nx = x + dx[i],ny = y + dy[i];
                if(nx >= 0 && nx < n && ny >= 0 && ny < m && !st[nx][ny]){
                    heap.push({nx,ny,max(h[nx][ny],he)});
                    st[nx][ny] = 1;
                }
            }
        }
        return res;
    }
};