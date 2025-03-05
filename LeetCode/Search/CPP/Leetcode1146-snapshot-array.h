#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

// 不要一整个数组更新，只要更新变化的id + val就可以了
// 去snap shot的时候找到 <= snap_id 的最大值就可以了

#if 0
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

#endif

class SnapshotArray {
 public:
  using PII = pair<int, int>;
  unordered_map<int, vector<PII>> mp;
  int snap_id = 0;
  SnapshotArray(int length) {
  }

  void set(int index, int val) {
    if (mp.contains(index) && mp[index].size() &&
        mp[index].back().first == snap_id) {
      mp[index].back().second = val;
      return;
    }
    mp[index].emplace_back(snap_id, val);
  }

  int snap() {
    return snap_id++;
  }

  int get(int index, int snap_id) {
    if (!mp.contains(index)) {
      return 0;
    }
    auto &snaps = mp[index];
    int l = 0, r = snaps.size() - 1;
    while (l <= r) {
      int mid = l + r >> 1;
      if (snaps[mid].first <= snap_id)
        l = mid + 1;
      else
        r = mid - 1;
    }
    if (r >= snaps.size() || r < 0) {
      return 0;
    }
    return snaps[r].second;
  }
};
