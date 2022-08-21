class Solution {
public:
    bool check(string &s,string& p) {
        if(p.size() > s.size()) return false;
        for(int i = 0;i < p.size();i++) {
            if(s[i] != p[i]) return false;
        }
        return true;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        int ans = -1,idx = 0,n = sentence.size();
        for(int i = 0;i < n;i++) {
            int j = i + 1;
            while(j < n && sentence[j] != ' ') j++;
            idx++;
            auto s = sentence.substr(i,j - i);
            if(check(s,searchWord)) {
                ans = idx;
                break;
            }
            i = j;
        }
        return ans;
    }
};