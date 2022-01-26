#include <string>

using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt = 0,res = 0;
        for(int i = 0;i < s.size();i++){
            if(s[i] == 'R') cnt++;
            else cnt--;
            if(cnt == 0) res++;
        }
        return res;
    }
};