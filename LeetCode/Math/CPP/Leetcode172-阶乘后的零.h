class Solution {
public:
    int trailingZeroes(int n) {
        int cnt2 = 0,cnt5 = 0;
        for(int i = 2,p = 1;i <= n;i += 2) {
            int cp = i;
            while(cp % 2 == 0) cp /= 2,cnt2++; 
        }
        for(int i = 5,p = 1;i <= n;i += 5) {
            int cp = i;
            while(cp % 5 == 0) cp /= 5,cnt5++;
        }
        int res = min(cnt2,cnt5);
        return res;
    }
};