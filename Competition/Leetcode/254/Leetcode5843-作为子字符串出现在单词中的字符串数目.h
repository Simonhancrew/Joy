#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;
        unordered_map<string,bool> mp;
        int n = word.size();
        for(int i = 0;i < word.size();i++){
            for(int j = i;j < n;j++){
                string cur = word.substr(i,j - i + 1);
                mp[cur] = true;
            }
        }
        for(auto pt:patterns){
            if(mp.count(pt)) ans++;
        }
        return ans;
    }
};