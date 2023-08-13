#include <vector>

using namespace std;

// 因为空的都在后面，其实可以考虑从最大的开始放

class Solution {
 public:
  void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int idx = m + n - 1;
    int i = m - 1, j = n - 1;
    while (i >= 0 && j >= 0) {
      if (nums1[i] >= nums2[j]) {
        nums1[idx] = nums1[i];
        i--;
      } else {
        nums1[idx] = nums2[j];
        j--;
      }
      idx--;
    }
    while (j >= 0) {
      nums1[idx--] = nums2[j--];
    }
  }
};
