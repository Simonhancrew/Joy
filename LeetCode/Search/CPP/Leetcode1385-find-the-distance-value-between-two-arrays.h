class Solution {
 public:
  int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d) {
    int ans = 0, n = arr2.size();
    ranges::sort(arr2);
    auto get = [&](int x) {
      int l = -1, r = n;
      while (l + 1 < r) {
        int mid = l + r >> 1;
        if (arr2[mid] < x - d) {
          l = mid;
        } else {
          r = mid;
        }
      }
      if (r == n || arr2[r] > x + d) {
        return true;
      }
      return false;
    };
    for (const auto x : arr1) {
      if (get(x))
        ++ans;
    }
    return ans;
  }
};
