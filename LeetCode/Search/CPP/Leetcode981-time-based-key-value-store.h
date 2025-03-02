class TimeMap {
 public:
  using PIS = pair<int, string>;
  unordered_map<string, vector<PIS>> mp;
  TimeMap() {
  }

  void set(string key, string value, int timestamp) {
    mp[key].emplace_back(timestamp, value);
  }

  string get(string key, int timestamp) {
    auto &vec = mp[key];
    int l = -1, r = vec.size();
    while (l + 1 < r) {
      int mid = l + r >> 1;
      if (vec[mid].first <= timestamp)
        l = mid;
      else
        r = mid;
    }
    if (l == -1 || vec[l].first > timestamp) {
      return "";
    }
    return vec[l].second;
  }
};
