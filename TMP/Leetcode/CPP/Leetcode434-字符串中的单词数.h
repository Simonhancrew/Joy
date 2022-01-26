#include <string>

using namespace std;

class Solution {
public:
    int countSegments(string s) {
        int cnt = 0,n = s.size();
        for(int i = 0;i < n;i++){
            while(i < n && s[i] == ' ') i++;
            if(i == n) break;
            while(i < n && s[i] != ' ') i++;
            cnt++;
        }
        return cnt;
    }
};