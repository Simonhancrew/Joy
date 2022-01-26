#include <unordered_map>

using namespace std;

// 哈希打卡题

class Solution {
public:
    int minimumSwitchingTimes(vector<vector<int>>& source, vector<vector<int>>& target) {
        unordered_map<int,int> mp;
        for(int i = 0;i < source.size();i++){
            for(int j = 0;j < source[0].size();j++){
                mp[source[i][j]]++;
            }
        }
        int res = 0;
        for(int i = 0;i < target.size();i++){
            for(int j = 0;j < target[0].size();j++){
                if(mp.count(target[i][j]) && mp[target[i][j]] > 0){
                    mp[target[i][j]]--;  
                }
                else res++;
            }
        }
        return res;
    }
};