/*
    记忆化搜索
*/
class Solution {
public:
    typedef long long LL;
    vector<vector<int>> q;
    vector<LL> f;
    LL dp(int t = 0){
        if(t >= q.size()) return 0;
        LL &v = f[t];
        if(v != -1) return v;
        int pt = q[t][0],bp = q[t][1];
        return v = max(pt + dp(t + bp + 1),dp(t + 1));
    }
    long long mostPoints(vector<vector<int>>& questions) {
        q = questions;
        int n = q.size();
        f = vector<LL> (n + 1,-1);
        return dp(0);
    }
};