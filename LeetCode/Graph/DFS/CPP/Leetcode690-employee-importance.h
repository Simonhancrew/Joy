#include <unordered_map>
#include <vector>

using namespace std;

class Employee {
public:
  int id;
  int importance;
  vector<int> subordinates;
};

class Solution {
public:
  int getImportance(vector<Employee *> employees, int id) {
    unordered_map<int, const Employee *> mp;
    for (auto *e : employees) {
      auto idx = e->id;
      mp[idx] = e;
    }
    auto dfs = [&](auto &&dfs, int id) {
      if (!mp.count(id)) {
        return 0;
      }
      int res = 0;
      auto *node = mp[id];
      res += node->importance;
      for (const auto &k : node->subordinates) {
        res += dfs(dfs, k);
      }
      return res;
    };
    return dfs(dfs, id);
  }
};
