#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

// 不要一整个数组更新，只要更新变化的id + val就可以了
// 去snap shot的时候找到 <= snap_id 的最大值就可以了

class SnapshotArray {
public:
  using PII = pair<int, int>;
  unordered_map<int, vector<PII>> rec;
  int id = 0;
  explicit SnapshotArray(int length) : rec(length) {}

  void set(int index, int val) { rec[index].emplace_back(id, val); }

  int snap() { return id++; }

  int get(int index, int snap_id) const {
    if (!rec.contains(index)) {
      return 0;
    }
    const auto &arr = rec.at(index);
    auto ans = ranges::lower_bound(arr, PII{snap_id + 1, 0}) - arr.begin() - 1;
    return ans >= 0 ? arr[ans].second : 0;
  }
};
