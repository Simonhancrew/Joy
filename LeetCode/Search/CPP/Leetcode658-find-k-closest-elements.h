/*
    二分 + 双指针
    左半边比x小，右半边>= x
    取值[l + 1,r]
*/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l = 0,r = n - 1;
        while(l < r) {
            int mid = l + r >> 1;
            if(arr[mid] > x) r--;
            else l++;
        }
        l = r - 1;
        while(k--) {
            if(l < 0) {
                r++;
            }else if(r >= n || x - arr[l] <= arr[r] - x) {
                l--;
            }else {
                r++;
            }
        }
        vector<int> ans(arr.begin() + l + 1,arr.begin() + r);
        return ans;
    }
};