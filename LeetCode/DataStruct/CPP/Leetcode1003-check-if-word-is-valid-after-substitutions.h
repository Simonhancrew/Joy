class Solution {
public:
    bool isValid(string s) {
        string stk;
        int n = s.size();
        for (int i = 0;i < n;i++) {
            stk += s[i];
            if (stk.size() >= 3 && stk.substr(stk.size() - 3) == "abc") {
                stk.erase(stk.end() - 3, stk.end());
            }
        }
        return stk.empty();
    }
};