/*
    想象成往前添加字母就行了，但是下标是反着来的
*/
class Solution {
public:
    typedef long long LL;
    const int P = 1e9 + 7;
    int countVowelPermutation(int n) {
        vector<vector<LL>> f(n + 1,vector<LL>(5));
        for(int i = 0;i < 5;i++) f[1][i] = 1;
        for(int i = 2;i <= n;i++){
            f[i][0] = f[i - 1][1];
            f[i][1] = f[i - 1][0] + f[i - 1][2];
            f[i][2] = f[i - 1][0] + f[i - 1][1] + f[i - 1][3] + f[i - 1][4];
            f[i][3] = f[i - 1][2] + f[i - 1][4];
            f[i][4] = f[i - 1][0];
            for(int j = 0;j < 5;j++) f[i][j] %= P;
        }
        LL ans = 0;
        for(int i = 0;i < 5;i++) ans += f[n][i];
        return ans % P;
    }
};