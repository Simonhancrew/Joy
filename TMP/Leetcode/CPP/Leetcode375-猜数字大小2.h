#include <cstring>
#include <numeric>

using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        int f[n + 2][n + 2];
        memset(f,0,sizeof f);
        for(int len = 2;len <= n;len++){
            for(int l = 1;l + len - 1 <= n;l++){
                int r = l + len - 1;
                f[l][r] = INT_MAX;
                for(int k = l;k <= r;k++){
                    f[l][r] = min(f[l][r],max(f[l][k - 1],f[k + 1][r]) + k);
                }
            }
        }
        return f[1][n];
    }
};