/*
    阶乘分解 + 2分答案
    答案数量中出现0 => 取x分解阶乘中2和5中，指数较小的。
    又因为要找到k，计算方法是固定的，找到5的个数
    类似一个数位dp
*/
class Solution {
public:
    using LL = long long;

    int preimageSizeFZF(int k) {
        return calcu(k) - calcu(k - 1);
    }   

    LL calcu(int k) {
        LL l = -1,r = 1e18;
        while(l < r) {
            LL mid = (l + r + 1) >> 1;
            if(f(mid) <= k) l = mid;
            else r = mid - 1;
        }
        return l;
    }

    LL f(LL x) {
        LL res = 0;
        while(x) res += x / 5, x /= 5;
        return res;
    }
};