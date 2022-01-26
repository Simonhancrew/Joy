#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0,idx = s.size() - 1;
        while(idx >= 0 && s[idx] == ' ') idx--;
        int r = idx;
        while(idx >= 0 && s[idx] != ' ') idx--;
        int l = idx;
        return r - l;
    }
};

#ifdef USE_STRINGSTREAM
class Solution {
public:
    int lengthOfLastWord(string s) {
        stringstream ss(s);
        string word;
        int res = 0;
        while(ss >> word) res = word.size();
        return res;
    }
};
#endif