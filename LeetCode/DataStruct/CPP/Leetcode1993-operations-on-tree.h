#include <vector>

using namespace std;

class LockingTree {
 public:
  vector<vector<int>> g;
  size_t n{};
  vector<int> p;
  vector<int> locks;
  LockingTree(vector<int>& parent) : p(std::move(parent)) {
    n = p.size();
    g.resize(n);
    locks.resize(n, -1);
    for (int i = 1; i < n; i++) {
      g[p[i]].push_back(i);
    }
  }

  bool lock(int num, int user) {
    if (locks[num] != -1) return false;
    locks[num] = user;
    return true;
  }

  bool unlock(int num, int user) {
    if (locks[num] != user) return false;
    locks[num] = -1;
    return true;
  }

  int dfs(int node) {
    int res = 0;
    if (locks[node] != -1) {
      locks[node] = -1;
      ++res;
    }
    for (const auto x : g[node]) {
      res += dfs(x);
    }
    return res;
  }

  bool upgrade(int num, int user) {
    if (locks[num] != -1) return false;
    for (int pa = p[num]; pa != -1; pa = p[pa]) {
      if (locks[pa] != -1) {
        return false;
      }
    }
    int sum = dfs(num);
    if (sum == 0) {
      return false;
    }
    locks[num] = user;
    return true;
  }
};
