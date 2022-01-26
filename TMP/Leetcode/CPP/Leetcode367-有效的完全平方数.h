class Solution {
public:
    typedef long long LL;
    bool isPerfectSquare(int num) {
        int l = 1,r = num;
        while(l < r){
            int mid = (LL)l + r >> 1;
            if((LL)mid * mid >= num) r = mid;
            else l = mid + 1;
        }
        return num % l == 0 && num == l * l;
    }
};