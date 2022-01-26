class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> in(n + 1),out(n + 1);
        for(int i = 0;i < trust.size();i++){
            int a = trust[i][0],b = trust[i][1];
            in[b]++;
            out[a]++;
        }
        int res = -1;
        for(int i = 1;i <= n;i++){
            if(out[i] == 0 && in[i] == n - 1) {
                if(res != -1) return - 1;
                res = i;
            }
        }
        return res;
    }
};