#include <string>

using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int res = 0;
        for(int i = 0,j = 0;i < s.size();i++){
            while(j < s.size() && s[j] == s[i]) j++;
            res = max(res,j - i);
            i = j - 1;
        }
        return res;
    }
};