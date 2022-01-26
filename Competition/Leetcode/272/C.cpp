class Solution {
public:
    typedef long long LL;
    long long getDescentPeriods(vector<int>& prices) {
        LL res = prices.size();
        int n = prices.size();
        for(int i = 0;i < n;i++){
            int j = i + 1;
            while(j < n && prices[j - 1] - prices[j] == 1) {
                j++;
            }
            // cout << j << endl;
            if(j - i > 1) {
                int t = j - i - 1;
                res += (LL)(1 + t) * t / 2;
            }
            i = j - 1;
        }
        return res;
    }
};