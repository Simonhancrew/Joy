class Solution {
 public:
  int maxChunksToSorted(vector<int> &arr) {
    auto b = arr;
    sort(b.begin(), b.end());
    int res = 0;
    unordered_map<int, int> mp;
    for (int i = 0, s = 0; i < arr.size(); i++) {
      if (mp[arr[i]] == 1)
        s--;
      else if (mp[arr[i]] == 0)
        s++;
      mp[arr[i]]--;
      if (mp[b[i]] == -1)
        s--;
      else if (mp[b[i]] == 0)
        s++;
      mp[b[i]]++;
      if (!s) res++;
    }
    return res;
  }
};