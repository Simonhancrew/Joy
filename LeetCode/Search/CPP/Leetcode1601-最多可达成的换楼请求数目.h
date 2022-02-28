class Solution {
public:
    int n;
    /*
        楼和请求都不大，直接二进制枚举
    */
    int maximumRequests(int _n, vector<vector<int>>& requests) {
        int ans = 0,m = requests.size();
        for(int i = 0;i < (1 << m);i++){
            int cnt = get(i);
            if(cnt <= ans) continue;
            if(check(i,requests)) ans = cnt;
        }
        return ans;
    }
    
    bool check(int x,vector<vector<int>>& arr){
        int sum = 0;
        vector<int> cnt(20);
        for(int i = 0;i < 16;i++) {
            if(x >> i & 1) {
                int f = arr[i][0],t = arr[i][1];
                --cnt[f],++cnt[t];
            }
        }
        for(int i = 0;i < 20;i++) 
            if(cnt[i] != 0) return false;
        return true;
    }

    int get(int x) {
        int cnt = 0;
        while(x){
            cnt++;
            x -= x & -x;
        }
        return cnt;
    }
};