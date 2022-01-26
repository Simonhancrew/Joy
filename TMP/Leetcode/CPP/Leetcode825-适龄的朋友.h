/*
    首先不考虑非法情况，找到发送的总请求数，然后剔除不合法的和自环
*/
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int n = ages.size(),res = n * n;
        int cnt[121] = {0};
        for(int i = 0;i < n;i++) cnt[ages[i]]++;
        for(int i = 1;i <= 120;i++){
            for(int j = 1;j <= 120;j++){
                if(j <= 0.5 * i + 7 || j > i){
                    res -= cnt[i] * cnt[j]; // 不合法中的自环 + 原本不合法的情况
                }else if(i == j) res -= cnt[i]; // 合法情况中的自环
            }
        }
        return res;
    }
};