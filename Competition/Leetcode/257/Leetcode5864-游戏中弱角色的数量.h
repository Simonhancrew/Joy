#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

// 排序的套路，类似于分组的思想，相等攻击的放一组，只要看攻击更小的组里面有没有防御小于这个组防御最大值的

#define GOODSOLUTION

#ifdef GOODSOLUTION
class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),[](auto& lhs,auto& rhs){
            return lhs[0] > rhs[0] ||(lhs[0] == rhs[0] && lhs[1] < rhs[1]);
        });
        int mx = -1,res = 0, n = p.size();
        // 因为攻击相同的时候，防守是从小到大的。必不可能出现同组误判
        for(int i = 0;i < n;i++){
            if(p[i][1] < mx) res++;
            else mx = p[i][1];
        }
        return res;
    }
};
#else

class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),[](auto& lhs,auto& rhs) {
            return lhs[0] < rhs[0] || (lhs[0] == rhs[0] && lhs[1] > rhs[1]);
        });
        stack<pair<int,int>> stk;
        int res = 0;
        for(int i = p.size() - 1;i >= 0;i--){
            while(stk.size() && stk.top().second <= p[i][1]) stk.pop();
            if(stk.size()) res++;
            stk.push({p[i][0],p[i][1]});
        }
        return res;
    }
};

#endif