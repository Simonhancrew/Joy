#if 0
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n == 0){
            return false;
        }
        while(n % 3 == 0){
            n /= 3;
        }
        return n == 1;
    }
};
#endif


// 复习一下快速幂和分解质因数，int范围内最大3 ** 19

class Solution {
public:
    typedef long long LL;
    int qmi(LL base,int p){
        int res = 1;
        while(p){
            if(p & 1) res = base * res;
            base *= base;
            p >>= 1;
        }
        return res;
    }
    bool isPowerOfThree(int n) {
        return n > 0 && qmi(3,19) % n == 0;
    }
};