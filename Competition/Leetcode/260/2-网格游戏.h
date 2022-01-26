#include <vector>
#include <numeric>

using namespace std;

// 不是数字三角

/*
    因为只有两行，所以枚举转弯的点就可以了
    要么是第一行的后缀和，要么是第二行的前缀和
*/

class Solution {
public:
    typedef long long LL;
    long long gridGame(vector<vector<int>>& grid) {
        LL res = (1ll << 62) - 1;
        LL left0 = accumulate(grid[0].begin(),grid[0].end(),0ll);
        LL left1 = 0;
        for(int i = 0;i < grid[0].size();i++){
            left0 -= (LL)grid[0][i];
            res = min(res,max(left0,left1));
            left1 += (LL)grid[1][i];
        }
        return res;
    }
};