class Solution {
 public:
  const int N = 1e9 + 7;
  int countNicePairs(vector<int>& nums) {
    unordered_map<int, int> mp;
    int ans = 0;
    auto calcu = [](int x) {
      string s = to_string(x);
      reverse(s.begin(), s.end());
      return x - stoi(s);
    };
    for (auto num : nums) {
      int cur = calcu(num);
      if (mp.count(cur)) {
        ans = (ans + mp[cur]) % N;
      }
      mp[cur]++;
    }
    return ans;
  }
};