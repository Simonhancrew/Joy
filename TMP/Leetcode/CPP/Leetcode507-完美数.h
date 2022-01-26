class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1) return false;
        int ans = 0;
        for(int i = 1;i <= num / i;i++){
            if(num % i == 0) ans += i;
            int t = num / i;
            if(t != num && t != i && num % t == 0) ans += t; 
        }
        return ans == num;
    }
};