class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> res;
        int n = digits.size();
        vector<int> st(n);
        for(int i = 0;i < digits.size();i++){
            if(digits[i] == 0) continue;
            st[i] = 1;
            for(int j = 0;j < digits.size();j++){
                if(st[j]) continue;
                st[j] = 1;
                for(int k = 0;k < digits.size();k++){
                    if(st[k]) continue;
                    st[k] = 1;
                    if(digits[k] % 2 == 0) {
                        int t = digits[i] * 100 + digits[j] * 10 + digits[k];
                        res.insert(t);
                    }
                    st[k] = 0;
                }             
                st[j] = 0;
            }
            st[i] = 0;
        }
        vector<int> ans;
        for(auto k : res) ans.push_back(k);
        return ans;
    }
};