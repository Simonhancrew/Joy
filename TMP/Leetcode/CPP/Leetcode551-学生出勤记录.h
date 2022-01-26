#include <string>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int it = 0,cnt = 0,n = s.size();
        while(it < s.size()){
            if(s[it] == 'P'){
                it++;
            }else if(s[it] == 'A'){
                cnt++;
                if(cnt >= 2) return false;
                it++;
            }else{
                int sum = 0;
                while(it < n && s[it] == 'L'){
                    it++;
                    sum++;
                }
                if(sum >= 3) return false;
            }
        }
        return true;
    }
};