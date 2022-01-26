class Solution {
public:
    int totalMoney(int n) {
        int ans = 0;
        for(int i = 0,cnt = 1;i < n;i++){
            if(i && i % 7 == 0) cnt++;
            ans += (cnt + i % 7);
        }
        return ans;
    }
};