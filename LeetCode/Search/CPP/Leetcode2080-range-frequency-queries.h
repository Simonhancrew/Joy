class RangeFreqQuery {
 public:
  unordered_map<int, vector<int>> mp;
  RangeFreqQuery(vector<int> &arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
      mp[arr[i]].push_back(i);
    }
  }

  int query(int left, int right, int value) {
    if (!mp.count(value)) {
      return 0;
    }
    auto &arr = mp[value];
    int l = -1, r = arr.size();
    while (l + 1 < r) {
      int mid = l + r >> 1;
      if (arr[mid] < left)
        l = mid;
      else
        r = mid;
    }
    auto ll = r;
    l = -1, r = arr.size();
    while (l + 1 < r) {
      int mid = l + r >> 1;
      if (arr[mid] <= right)
        l = mid;
      else
        r = mid;
    }
    return r - ll;
  }
};
