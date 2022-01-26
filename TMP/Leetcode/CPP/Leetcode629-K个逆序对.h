#include <cstring>

using namespace std;

class Solution {
public:
    const int mod = 1e9 + 7;
    int kInversePairs(int n, int k) {
        int f[n + 1][k + 1];
        memset(f,0,sizeof f);
        f[1][0] = 1;
        for(int i = 2;i <= n;i++){
            long long s = 0;
            for(int j = 0;j <= k;j++){
                s += f[i - 1][j];
                if(j - i >= 0) s -= f[i - 1][j - i];
                f[i][j] = s % mod; 
            }
        }
        return f[n][k] % mod;
    }
};