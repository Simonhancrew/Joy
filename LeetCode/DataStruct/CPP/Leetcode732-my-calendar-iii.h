/*
    差分，头+，尾-，看看中间最大是多少
*/
class MyCalendarThree {
 public:
  map<int, int> mp;
  MyCalendarThree() {}

  int book(int start, int end) {
    mp[start]++, mp[end]--;
    int res = 0, sum = 0;
    for (auto &[k, v] : mp) {
      sum += v;
      res = max(sum, res);
    }
    return res;
  }
};

/*
    动态开点线段树，本质来讲应该有一个pushdown的，但是只需要整体线段的最大值
    不需要查询小线段的最大值，所以可以不用pushdown，只要更新的大线段是对的就可以了
*/

#ifdef SEG
class MyCalendarThree {
 public:
  MyCalendarThree() : tr(10) {
  }

  int book(int startTime, int endTime) {
    add(1, 0, 1e9, startTime, endTime - 1);
    return tr[1].first;
  }

 private:
  using PII = pair<int, int>;
  unordered_map<int, PII> tr;

  void pushdown(int id) {
    tr[id << 1].first += tr[id].second;
    tr[id << 1 | 1].first += tr[id].second;
    tr[id << 1 | 1].second += tr[id].second;
    tr[id << 1].second += tr[id].second;
    tr[id].second = 0;
  }

  void add(int id, int ul, int ur, int kl, int kr) {
    if (ul >= kl && ur <= kr) {
      tr[id].first++;
      tr[id].second++;
      return;
    }
    pushdown(id);
    int mid = (ul + ur) >> 1;
    if (mid >= kl)
      add(id << 1, ul, mid, kl, kr);
    if (mid < kr)
      add(id << 1 | 1, mid + 1, ur, kl, kr);
    tr[id].first = max(tr[id << 1].first, tr[id << 1 | 1].first);
  }
};
#endif
