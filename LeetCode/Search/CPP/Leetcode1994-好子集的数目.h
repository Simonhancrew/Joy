/*
    因为数的大小范围只有30，做一个dfs就可以了。
*/
class Solution {
public:
    const int P = 1e9 + 7;
    typedef long long LL;
    int s[31] = {0};
    int st[31] = {0};
    int g[31][31] = {0};
    int base = 1;
    vector<int> path;

    int dfs(int u,int sum) {
        if(!sum) return 0;
        if(u > 30) {
            if(path.empty()) return 0;
            return sum * (LL)base % P;
        }
        int res = dfs(u + 1,sum);
        if(!st[u]) {
            bool flag = true;
            for(auto x : path) {
                if(g[x][u]) {
                    flag = false;
                    break;
                } 
            }
            if(flag) {
                path.push_back(u);
                res = (res + dfs(u + 1,sum * (LL)s[u] % P)) % P;
                path.pop_back();
            }
        }
        return res;
    }

    int numberOfGoodSubsets(vector<int>& nums) {
        for(int i = 0;i < nums.size();i++) s[nums[i]]++;
        // 对1特判，选和不选，附加的方案就是pow(2,cnt)
        for(int i = 0;i < s[1];i++) base = base * 2 % P; 
        // 去掉平方数
        for(int i = 2;i * i <= 30;i++) {
            for(int j = 1;j * i * i <= 30;j++) st[j * i * i] = 1;
        }
        // 去掉有大于1公因子的
        for(int i = 1;i <= 30;i++) {
            for(int j = 1;j <= 30;j++){
                if(gcd(i,j) > 1) g[i][j] = 1;
            }
        }
        return dfs(2,1);
    }
};