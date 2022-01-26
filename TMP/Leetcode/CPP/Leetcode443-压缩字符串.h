#include <vector>
#include <string>

using namespace std;

#define BADSOLU 0

#if BADSOLU
class Solution {
public:
    int compress(vector<char>& chars) {
        vector<char> rec;
        int n = chars.size();
        for(int i = 0;i < n;i++){
            string s;
            char cur = chars[i];
            s += cur;
            int j = i;
            while(j < n && chars[i] == chars[j]) j++;
            int cnt = j - i;
            if(cnt != 1) s+= to_string(cnt);
            for(auto ch:s) rec.push_back(ch);
            i = j - 1;
        }
        chars = rec;
        return rec.size();
    }
};
#endif

class Solution {
public:
    int compress(vector<char>& chars) {
        int k = 0,n = chars.size();
        for(int i = 0;i < n;i++){
            int j = i;
            while(j < n && chars[j] == chars[i]) j++;
            int cnt = j - i;
            chars[k++] = chars[i];
            if(cnt > 1){
                int t = k;
                while(cnt){
                    chars[t++] = '0' + cnt % 10;
                    cnt /= 10;
                }
                reverse(chars.begin()+k,chars.begin() + t);
                k = t;
            }
            i = j - 1;
        }
        return k;
    }
};