#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return -1;
        }
        int start = 0,end = nums.size() - 1;
        while(start <= end){
            //不要让mid溢出int
            int mid = start + (end - start) / 2;
            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        } 
        return -1;
    }
};





#if 0

class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = lower_bound(nums.begin(),nums.end(),target);
        if(*it != target) return -1;
        return it - nums.begin();
    }
};

#endif


#if 0

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0,r = nums.size() - 1;
        while(l < r){
            int mid = l + r + 1 >> 1;
            if(nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        if(nums[l] == target) return l;
        return -1;
    }
};

#endif