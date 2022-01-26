class Solution {
public:
    string truncateSentence(string s, int k) {
        string res;
        for(int i = 0;i < s.size() && k > 0;i++){
            if(s[i] == ' ') k--;
            if(k) res += s[i];
        }
        return res;
    }
};