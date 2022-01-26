#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l = nums[0],r = nums.back();
        return gcd(l,r);
    }
    int gcd(int l,int r){
        return r?gcd(r,l %  r): l;
    }
};