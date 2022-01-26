#include <algorithm>
#include <vector>

using namespace std;

// 最大值最小应该第一时间想到2分

class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int l = 1,r = *max_element(q.begin(),q.end());
        auto check = [&](int u){
            int res = 0;
            for(auto qt : q) {
                res += (qt + u - 1) / u;
            }
            return res;
        };
        while(l < r){
            int mid = (l + r) >> 1;
            if(check(mid) <= n) r = mid;
            else l = mid + 1;
        }
        return r;
    }
};