#include <vector>
#include <string>

using namespace std;

using LL = long long;

// 维护一个表达式结构a + b * _,碰到不同的情况分别考虑

class Solution {
public:
    vector<string> res;
    string path;
    vector<string> addOperators(string num, int target) {
        path.resize(100);
        dfs(num,0,0,0,1,target);
        return res;
    }
    void dfs(const string& num,int u,int len,LL a,LL b,int target){
        if(u == num.size()){
            if(a == target) res.push_back(path.substr(0,len - 1));
            return;
        }
        LL c = 0;
        for(int i = u;i < num.size();i++){
            c = c * 10 + num[i] - '0';
            path[len++] = num[i];
            
            path[len] = '+';
            dfs(num,i + 1,len + 1,a + b * c,1,target);

            if(i + 1 < num.size()){
                path[len] = '-';
                dfs(num,i + 1,len + 1,a + b * c,-1,target);

                path[len] = '*';
                dfs(num,i + 1,len + 1,a,b * c,target);
            }
            if(num[u] == '0') break;
        }
    }
};