#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = accumulate(machines.begin(),machines.end(),0),n = machines.size();
        if(sum % n != 0) return -1;
        int avg = sum / n;
        // 必定存在一个洗衣机运送的衣服数量等于答案数
        // 最优情况下，工作最久的洗衣机就是工作步数最大值
        int l = 0,r = sum,ans = 0;
        for(int i = 0;i < n;i++){
            r -= machines[i];
            int l2r = max(i * avg - l,0);
            int r2l = max((n - i - 1) * avg - r,0);
            ans = max(ans,r2l + l2r);
            l += machines[i];
        }
        return ans;
    }
};