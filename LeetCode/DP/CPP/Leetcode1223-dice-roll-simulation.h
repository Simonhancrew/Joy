class Solution {
public:
    static const int N = 5e3 + 10, MOD = 1e9 + 7;
    int f[N][7][16];
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(f, 0, sizeof f);
        for (int i = 0;i < 6;i++) f[1][i][1] = 1;
        for (int i = 1;i < n;i++) {
            for (int j = 0; j < 6;j++) {
                for (int k = 1;k <= rollMax[j];k++) {
                    for (int u = 0;u < 6;u++) {
                        int len = 1;
                        if (u == j) {
                            len = k + 1;
                            if (len > rollMax[j]) continue;
                        }
                        f[i + 1][u][len] = (f[i + 1][u][len] + f[i][j][k]) % MOD;
                    }
                }
            }
        }
        int res = 0;
        for(int i = 0;i < 6;i++) {
            for (int j = 1;j <= rollMax[i];j++) {
                res = (res + f[n][i][j]) % MOD;
            }
        }
        return res;
    }
};
