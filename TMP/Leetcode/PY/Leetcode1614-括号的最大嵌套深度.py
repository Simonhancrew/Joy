class Solution {
public:
    int maxDepth(string s) {
        int ans = 0,n = s.size();
        for(int i = 0,cnt = 0;i < n;i++){
            if(s[i] == '(') cnt++,ans = max(ans,cnt);
            else if(s[i] == ')') cnt--;
        }
        return ans;
    }
};