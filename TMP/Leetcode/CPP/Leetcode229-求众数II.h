#include <vector>

using namespace std;

#if 0
#include <unordered_map>
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto num : nums){
            mp[num]++;
        }
        int n = nums.size();
        vector<int> ans;
        for(auto [k,v] : mp){
            if(v > n / 3) ans.push_back(k); 
        }
        return ans;
    }
};
#endif

// 摩尔投票选举扩充到1/k的情况
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1,c2,r1 = 0,r2 = 0,n = nums.size();
        for(auto num : nums){
            if(r1 && c1 == num) r1++;
            else if(r2 && c2 == num) r2++;
            else if(!r1) c1 = num,r1 = 1;
            else if(!r2) c2 = num,r2 = 1;
            else r1--,r2--;
        }
        r1 = 0,r2 = 0;
        for(auto num : nums){
            if(num == c1) r1++;
            else if(num == c2) r2++;
        }
        vector<int> ans;
        if(r1 > n / 3) ans.push_back(c1);
        if(r2 > n / 3) ans.push_back(c2);
        return ans;
    }
};