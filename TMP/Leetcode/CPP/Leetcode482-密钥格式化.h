#include <string>

using namespace std;

// 这种头部需要特判的从尾部开始做就好了

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans;
        for(int i = s.size() - 1,cnt = 0;i >= 0;i--){
            if(s[i] == '-') continue;
            if(cnt == k) {
                ans += '-';
                cnt = 0;
            }
            ans += isupper(s[i]) ? s[i] : toupper(s[i]);
            cnt++;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};