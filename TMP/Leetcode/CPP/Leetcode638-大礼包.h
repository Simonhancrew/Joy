#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


// 因为礼包可以无数次选，实际需要的物品是有限制的可以看作一个完全背包问题
// 背包体积就是总共物品的多少dp[x][y] = min(dp[x - 1][y],dp[x][y - v] + w)
// 物品最多拿10个，实际做的话需要开10维，可以考虑一个压缩，16进制
// 用一个记忆化搜索来减少计算


class Solution {
public:
    vector<unordered_map<int,int>> f;
    vector<vector<int>> sp;
    vector<int> pr;
    int n;
    // 从前x个礼包中选，凑成物品状态y的最小价值
    int dp(int x,int y){
        if(f[x].count(y)) return f[x][y];
        if(!x) {
            for(int i = 0;i < n;i++){
                int c = y >> i * 4 & 15;
                f[x][y] += c * pr[i];
            }
            return f[x][y];
        }
        // 完全背包
        f[x][y] = dp(x - 1,y);
        int st = 0; // 更新之后的状态
        auto s = sp[x - 1]; // 当前礼包
        for(int i = n - 1;i >= 0;i--){
            int c = y >> i * 4 & 15; // 当前状态下需要多少个物品i
            if(c < s[i]) { // 礼包不能恰好凑到这个值
                st = -1;
                break;
            }
            st = st * 16 + c - s[i];
        }
        if(st != -1) {
            f[x][y] = min(f[x][y],dp(x,st) + s.back());
        }
        return f[x][y];
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        n = needs.size();
        pr = price,sp = special;
        int state = 0;
        f.resize(special.size() + 1,unordered_map<int,int> ());
        for(int i = n - 1;i >= 0;i--){ // 16进制压缩
            state = state * 16 + needs[i];
        }
        return dp(sp.size(),state);
    }
};