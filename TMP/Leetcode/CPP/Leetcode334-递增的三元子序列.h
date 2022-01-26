#if 0
/*
    开额外空间记录左小右大
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> lmn(n),rmx(n);
        for(int i = 0;i < n;i++){
            if(!i) lmn[i] = nums[i];
            else lmn[i] = min(lmn[i - 1],nums[i]);
        } 
        for(int i = n - 1;i >= 0;i--){
            if(i == n - 1) rmx[i] = nums[i];
            else rmx[i] = max(rmx[i + 1],nums[i]);
        }
        for(int i = 0;i < n;i++){
            if(lmn[i] < nums[i] && rmx[i] > nums[i]) return true;
        }
        return false;
    }
};
#endif

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a[2] = {0};
        a[0] = INT_MAX,a[1] = INT_MAX;
        for(auto n : nums){
            int k = 2;
            while(k > 0 && a[k - 1] >= n) k--;
            if(k == 2) return true;
            a[k] = n;
        }
        return false;
    }
};