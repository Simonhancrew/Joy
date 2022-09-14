class AllOne {
 public:
  list<pair<unordered_set<string>, int>> lst;
  unordered_map<string, list<pair<unordered_set<string>, int>>::iterator> node;

  AllOne() {}

  void inc(string key) {
    if (node.count(key)) {
      auto cur = node[key], ne = next(cur);
      if (ne == lst.end() || cur->second + 1 < ne->second) {
        unordered_set<string> s({key});
        node[key] = lst.emplace(ne, s, cur->second + 1);
      } else {
        ne->first.emplace(key);
        node[key] = ne;
      }
      // delete old
      cur->first.erase(key);
      if (cur->first.empty()) lst.erase(cur);
    } else {
      if (lst.empty() || lst.begin()->second > 1) {
        unordered_set<string> s({key});
        lst.emplace_front(s, 1);
      } else {
        lst.begin()->first.emplace(key);
      }
      node[key] = lst.begin();
    }
  }

  void dec(string key) {
    auto cur = node[key];
    if (cur->second == 1) {
      node.erase(key);
    } else {
      auto pre = prev(cur);
      if (cur == lst.begin() || pre->second < cur->second - 1) {
        unordered_set<string> s({key});
        node[key] = lst.emplace(cur, s, cur->second - 1);
      } else {
        pre->first.emplace(key);
        node[key] = pre;
      }
    }
    cur->first.erase(key);
    if (cur->first.empty()) {
      lst.erase(cur);
    }
  }

  string getMaxKey() { return lst.empty() ? "" : *lst.rbegin()->first.begin(); }

  string getMinKey() { return lst.empty() ? "" : *lst.begin()->first.begin(); }
};
