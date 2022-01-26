#include <string>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        for(int i = 0;i < n;i++){
            if(word[i] == ' ') continue;
            int j = i + 1;
            while(j < n && word[j] != ' ') j++;
            string cur = word.substr(i,j - i);
            if(!check(cur)) return false;
            i = j;
        }
        return true;
    }
    bool check(string s){
        int n = s.size();
        int cnt = 0;
        for(int i = 0;i < n;i++){
            if(isupper(s[i])) cnt++;
        }
        if(cnt == 0 || cnt == n) return true;
        if(cnt == 1 && isupper(s[0])) return true;
        return false;
    }
};