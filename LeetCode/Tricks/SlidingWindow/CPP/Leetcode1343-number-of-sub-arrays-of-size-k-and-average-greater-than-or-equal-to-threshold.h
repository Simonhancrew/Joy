class Solution {
public:
  int numOfSubarrays(vector<int> &arr, int k, int threshold) {
    int ans = 0;
    int acc = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      acc += arr[i];
      if (i < k - 1)
        continue;
      if (acc / k >= threshold) {
        ans++;
      }
      acc -= arr[i - k + 1];
    }
    return ans;
  }
};
