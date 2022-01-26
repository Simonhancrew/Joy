#include <unordered_map>
using namespace std;

class Solution {
public:
    typedef long long LL;
    unordered_map<LL,int> f;
    int integerReplacement(int n) {
        return dp(n);
    }
    int dp(LL n){
        if(n == 1) return 0;
        if(f.count(n)) return f[n];
        if(n % 2 == 0) return f[n] = dp(n / 2) + 1;
        return f[n] = min(dp(n + 1),dp(n - 1)) + 1;
    }
};