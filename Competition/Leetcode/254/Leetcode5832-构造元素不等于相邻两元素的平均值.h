#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int it = 0;
        vector<int> res(n);
        for(int i = 0;i < n;i+=2){
            res[i] = nums[it++];
        }
        for(int i = 1;i < n;i+=2){
            res[i] = nums[it++];
        }
        return res;
    }   
};