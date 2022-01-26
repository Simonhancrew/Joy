#include <algorithm>

using namespace std;

class Solution {
public:
    int getMaximumGenerated(int n) {
        if(n == 0) return 0;
        int res[n + 1];
        memset(res,0,sizeof res);
        res[0] = 0,res[1] = 1;
        for(int i = 1;2 * i <= n;i++){
            res[2 * i] = res[i];
            if(2 * i + 1 <= n) res[2 * i + 1] = res[i] + res[i + 1];
        }
        return *max_element(res,res + n + 1);
    }
};