#include <string>

using namespace std;

// 比较小，直接爆搜就可以了
// 注意能加引用的尽量加引用吧
class Solution {
public:
    int res = 0;
    string s;
    int maxProduct(string ss) {
        string s1,s2;
        s = ss;
        dfs(0,s1,s2);
        return res;
    }

    void dfs(int u,string s1,string s2){
        if(check(s1) && check(s2)) res = max(res,int(s1.size() * s2.size()));
        if(u == s.size()) return;
        dfs(u + 1,s1 + s[u],s2);
        dfs(u + 1,s1,s2 + s[u]);
        dfs(u + 1,s1,s2);
    }

    bool check(string &s){
        int l = 0,r = s.size() - 1;
        while(l < r){
            if(s[l] != s[r]) return false;
            l++,r--;
        }
        return true;
    }
};