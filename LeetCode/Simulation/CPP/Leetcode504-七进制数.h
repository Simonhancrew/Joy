class Solution {
public:
    string convertToBase7(int num) {
        string ans;
        if(!num) return "0";
        bool flag = false;
        if(num < 0) {
            num = -num;
            flag = true;
        }
        while(num){
            ans += to_string(num % 7);
            num /= 7;
        }
        if(flag) ans += '-';
        reverse(ans.begin(),ans.end());
        return ans;
    }
};