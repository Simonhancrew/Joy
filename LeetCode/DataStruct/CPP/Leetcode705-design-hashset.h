#include <array>
#include <vector>

using namespace std;

class MyHashSet {
public:
  MyHashSet() {}

  void add(int key) {
    if (contains(key)) {
      return;
    }
    auto loc = key % MOD;
    rec[loc].push_back(key);
  }

  void remove(int key) {
    auto loc = key % MOD;
    if (rec[loc].empty()) {
      return;
    }
    for (auto it = rec[loc].begin(); it != rec[loc].end(); it++) {
      if (*it == key) {
        rec[loc].erase(it);
        return;
      }
    }
  }

  bool contains(int key) {
    auto loc = key % MOD;
    if (rec[loc].empty()) {
      return false;
    }
    for (const auto x : rec[loc]) {
      if (x == key) {
        return true;
      }
    }
    return false;
  }

  static constexpr int MOD = 1331;
  array<vector<int>, MOD> rec;
};
