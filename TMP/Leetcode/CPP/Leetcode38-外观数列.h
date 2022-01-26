#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1) return "1";
        string s = "1";
        for(int i = 0;i < n - 1;i++){
            string t;
            for(int j = 0;j < s.size();j++){
                int k = j;
                while(j < s.size() && s[j] == s[k]) k++;
                int cnt = k - j;
                t += to_string(cnt) + s[j];
                j = k - 1;
            }
            s = t;
        }
        return s;
    }
};