class Solution {
 public:
  vector<string> findLongestSubarray(vector<string>& array) {
    unordered_map<int, int> mp;
    int s = 0, mx = 0, st = -1, n = array.size();
    mp[0] = -1;
    for (int i = 0; i < n; i++) {
      if (isalpha(array[i][0])) {
        s++;
      } else {
        s--;
      }
      if (mp.count(s)) {
        int pre = mp[s];
        int cur_len = i - pre;
        if (cur_len > mx) {
          mx = cur_len;
          st = pre + 1;
        }
      } else {
        mp[s] = i;
      }
    }
    if (mx == 0) {
      return {};
    }
    return {array.begin() + st, array.begin() + st + mx};
  }
};