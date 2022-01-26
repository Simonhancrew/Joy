class Solution {
public:
    bool check(string &s) {
        int l = 0,r = s.size() - 1;
        while(l < r){
            if(s[l] != s[r]) return false;
            l++,r--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        string ans;
        for(auto &s : words) {
            if(check(s)) {
                ans = s;
                break;
            }
        }
        return ans;
    }
};