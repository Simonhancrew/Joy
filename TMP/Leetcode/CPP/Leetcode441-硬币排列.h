//在1-n中找=二分的找确定的位置，即第一个sum>=sum(mid)的pos;
#if 0
class Solution {
public:
    int arrangeCoins(int n) {
        int low = 1;
        int high = n;
        while(low <= high){
            int mid = low + (high - low) / 2;
            long sum = mid * (mid + 1) / 2;
            if(sum > n)
                high = mid - 1;
            else if(sum == n)
                return mid;
            else if(sum < n)
                low = mid + 1;
        }
        return low - 1;
    }
};
#endif

class Solution {
public:
    typedef long long LL;
    int arrangeCoins(int n) {
        int l = 1,r = n;
        while(l < r){
            LL mid = (LL)l + r + 1 >> 1;
            LL sum = (LL)(mid + 1) * mid / 2;
            if(sum <= n) l = mid;
            else r = mid - 1;
        }
        return l;
    }
};