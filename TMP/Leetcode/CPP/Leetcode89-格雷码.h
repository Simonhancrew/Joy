/*
    格雷码生成规律，对称复制之后，前一半末尾补0，后一半末尾补1
*/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans(1,0);
        while(n--){
            int t = ans.size();
            ans.resize(t * 2);
            for(int i = t - 1,j = t;i >= 0;i--,j++){
                ans[i] *= 2;
                ans[j] = ans[i] + 1;
            }
        }
        return ans;
    }
};