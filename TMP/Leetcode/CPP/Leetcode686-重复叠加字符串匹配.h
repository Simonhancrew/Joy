#include <string>
#include <vector>

using namespace std;
#if 0
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int i = 1;
        string s = a;
        while(b.size() > s.size()){
            s += a;
            i++;
        }
        if(s.find(b) != s.npos) return i;
        else {
            i++;
            s += a;
            if(s.find(b) != s.npos) return i;
        }
        return -1;
    }
};
#endif
/*
    KMP
*/
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string s = a;
        while(s.size() < b.size()) s += a;
        s += a;
        int n = b.size(),m = s.size();
        s = ' ' + s,b = ' ' + b;
        vector<int> ne(n + 1);
        for(int i = 2,j = 0;i <= n;i++){
            while(j && b[i] != b[j + 1]) j = ne[j];
            if(b[i] == b[j + 1]) j++;
            ne[i] = j;
        }
        for(int i = 1,j = 0;i <= m;i++){
            while(j && s[i] != b[j + 1]) j = ne[j];
            if(s[i] == b[j + 1]) j ++;
            if(j == n) {
                return (i + a.size() - 1) / a.size();
            }
        }
        return -1;
    }
};