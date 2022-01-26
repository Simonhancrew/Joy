#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int res = 0;
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto x : nums) mp[x]++;
        for(auto& [k,v] : mp){
            if(mp.count(k - 1)) {
                res = max(res,v + mp[k - 1]); 
            }
        }
        return res;
    }
};