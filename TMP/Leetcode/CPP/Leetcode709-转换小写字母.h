class Solution {
public:
    string toLowerCase(string s) {
        string res;
        for(auto ch : s) {
            res += tolower(ch);
        }
        return res;
    }
};