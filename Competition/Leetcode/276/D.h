/*
    t分钟完成，每个电池能支持的时间就是min(t,bat[i])
    其和为sum,只要sum / t >= n 当前解就是成立的
    二分答案
*/

class Solution {
public:
    typedef long long LL;
    long long maxRunTime(int n, vector<int>& batteries) {
        LL l = 1,r = 1e16 + 10;
        auto check = [&](LL mid) {
            LL sum = 0;
            for(int i : batteries) sum += min((LL)i,mid);
            return sum / mid >= n;
        };
        while(l < r){
            LL mid = l + r + 1 >> 1;
            if(check(mid)) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};