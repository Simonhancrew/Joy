// 1 必须不一样才能换
// 2 换完之后，不能有0
// 3 分成两组，变成 1 和 2**p - 1

class Solution {
public:
    typedef long long LL;
    const int MOD = 1e9 + 7;
    int minNonZeroProduct(int p) {
        LL a = (LL)(1ll << p);
        return (a - 1) % MOD * qmi(a-2, (1ll<<(p-1))-1) % MOD;
    }
    LL qmi(LL a,LL k){
        LL res = 1;
        a %= MOD;
        while(k){
            if(k & 1) res = res * a % MOD;
            a = (a * a) % MOD;
            k >>= 1;
        }
        return res;
    }
};