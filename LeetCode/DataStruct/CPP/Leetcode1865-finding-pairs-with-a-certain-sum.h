class FindSumPairs {
 public:
  const vector<int> nums1;
  vector<int> nums2;
  unordered_map<int, int> mp;
  FindSumPairs(vector<int> &nums1, vector<int> &nums2)
      : nums1(std::move(nums1)), nums2(std::move(nums2)) {
    for (const auto x : this->nums2) {
      mp[x]++;
    }
  }

  void add(int index, int val) {
    auto pre = nums2[index];
    nums2[index] += val;
    mp[pre]--;
    mp[nums2[index]]++;
  }

  int count(int tot) {
    int ans = 0;
    for (const auto x : nums1) {
      int y = tot - x;
      if (mp.contains(y)) {
        ans += mp[y];
      }
    }
    return ans;
  }
};
