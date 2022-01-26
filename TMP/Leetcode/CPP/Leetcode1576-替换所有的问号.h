class Solution {
public:
    string modifyString(string s) {
        int n = s.size();
        for(int i = 0;i < n;i++){
            if(s[i] == '?'){
                for(char t = 'a';t <= 'z';t++){
                    if((i > 0 && s[i - 1] == t) || (i < n - 1 && s[i + 1] == t)) continue;
                    s[i] = t;
                    break;
                }
            }
        }
        return s;
    }
};