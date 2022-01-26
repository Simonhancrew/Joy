#include <climits>
#if 0
class Solution {
public:
    int divide(int dividend, int divisor){
        if(dividend == 0){
            return 0;
        }
        if(divisor == 1) return dividend;
        if(divisor == -1){
            if(dividend > INT_MIN){
                return -dividend;
            }
            return INT_MAX;
        }
        long a = dividend,b = divisor;
        int sign = -1;
        if((a>0 && b > 0) || (a < 0 && b < 0)){
            sign = 1;
        }
        a = a > 0?a:-a;
        b = b > 0?b:-b;
        long res = div(a,b);
        if(sign>0){
            return res > INT_MAX?INT_MAX:res;
        }
        return -res < INT_MIN?INT_MIN:-res;
    }
private:    
    long div(long a,long b){
        if(a < b) return 0;
        long count = 1;
        long tb = b;
        while(tb +tb <= a){
            count += count;
            tb += tb;
        }
        return count + div(a - tb,b);
    }
};
#endif

// a / b 的范围一定在[0,a]以内，所以二分之后做一个倍增乘法就行了
// 倍增乘法的思路来自于快速幂

class Solution {
public:
    using ll = long long;
    int divide(int dividend, int divisor) {
        if(divisor == 1 || dividend == 0) return dividend;
        if(divisor == -1) {
            if(dividend > INT_MIN) return -dividend;
            return INT_MAX;
        } 
        bool flag = false;
        if((dividend ^ divisor) < 0) flag = true;
        ll a = dividend,b = divisor;
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;
        ll l = 0,r = a;
        while(l < r){
            ll mid = l + r + 1 >> 1;
            if(mul(mid,b) <= a) l = mid;
            else r = mid - 1;
        }
        l = flag ? -l : l;
        if(l > INT_MAX || l < INT_MIN) l = INT_MAX;
        return l;
    }
    ll mul(ll mid,ll b){
        ll res = 0;
        while(b){
            if(b & 1) res += mid;
            mid += mid;
            b >>= 1;
        }
        return res;
    }
};