#include <vector>

using namespace std;

// 主要思考的是mid存在，mid+1是否存在的问题
// 可以证明，能进入while的话，mid = l + r >> 1的话，mid + 1一定存在
// 极限条件l == r的时候，mid才等于r，不存在mid+1

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0,r = nums.size();
        while(l < r){
            int mid = l + r >> 1;
            if(nums[mid] > nums[mid + 1]) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};