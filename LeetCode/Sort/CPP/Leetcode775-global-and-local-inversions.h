class Solution {
public:
    int partial = 0;
    static const int N = 1e5 + 10;
    int arr[N];
    int merge_sort(vector<int>& nums, int l, int r) {
        if(l == r) return 0;
        int mid = l + r >> 1;
        int res = merge_sort(nums,l, mid) + merge_sort(nums, mid + 1, r);
        if(res > partial) return -1;
        int i = l, j = mid + 1, k = 0;
        while(i <= mid && j <= r) {
            if(nums[i] <= nums[j]) {
                arr[k++] = nums[i++];
            } else {
                res += mid - i + 1;
                arr[k++] = nums[j++];
            }
        }
        while(i <= mid) arr[k++] = nums[i++];
        while(j <= r) arr[k++] = nums[j++];
        for(int i = l, j = 0;i <= r;i++,j++) nums[i] = arr[j];
        return res;
    }

    bool isIdealPermutation(vector<int>& nums) {
        int n = nums.size();
        memset(arr, 0, sizeof arr);
        for(int i = 0;i < n - 1;i++) {
            if(nums[i] > nums[i + 1]) partial++;
        }
        int res = merge_sort(nums, 0, n - 1);
        if(res == -1) return false;
        return res == partial;
    }
};
