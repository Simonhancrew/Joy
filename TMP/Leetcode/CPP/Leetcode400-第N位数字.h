#include <string>

using namespace std;

/*
    经典找规律
    1-9：    cnt(每个数的位数)=1，len(所有数)=9
    10-99：  cnt = 2,len = 90
    100-999：cnt = 3,len = 900
    则首先推断出全局单个数，这个位出现在那个数中
    然后再推算出这个数出现在当前这个数的哪一位就可以了
*/

class Solution {
public:
    typedef long long LL;
    int findNthDigit(int n) {
        LL cnt = 1,base = 9,s = 1;
        while(n > cnt * base) {
            n -= cnt * base;
            s *= 10;
            base *= 10,cnt++;
        }
        s += (n + cnt - 1) / cnt - 1;
        n = n % cnt ? n % cnt : cnt;
        return to_string(s)[n - 1] - '0';
    }
};