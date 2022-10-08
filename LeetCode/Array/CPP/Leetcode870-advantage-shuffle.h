class Solution {
 public:
  vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {
    sort(nums1.begin(), nums1.end());
    int n = nums1.size();
    vector<int> id(n);
    for (int i = 0; i < n; i++)
      id[i] = i;
    sort(id.begin(), id.end(), [&nums2](int lhs, int rhs) {
      return nums2[lhs] < nums2[rhs];
    });
    vector<int> ans(n);
    int l = 0, r = n - 1;
    for (int i = 0; i < n; i++) {
      if (nums1[i] > nums2[id[l]])
        ans[id[l++]] = nums1[i];
      else
        ans[id[r--]] = nums1[i];
    }
    return ans;
  }
};
