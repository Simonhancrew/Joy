#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        int n = s.size();
        if(n < 10) return res;
        map<string,int> mp;
        for(int i = 0;i <= n - 10;i++){
            mp[s.substr(i,10)]++;
            if(mp[s.substr(i,10)] == 2){
                res.push_back(s.substr(i,10));
            }
        }
        return res;
    }
};