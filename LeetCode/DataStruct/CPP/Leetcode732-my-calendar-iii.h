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
#define mx first
#define tag second
class MyCalendarThree {
 public:
  // first max,second tag
  unordered_map<int, pair<int, int>> tr;
  MyCalendarThree() {}
  // 使用大写字母常数化需要修改的区间，tr[idx]和其左右儿子（l,r）相关
  void update(int S, int E, int l, int r, int idx) {
    if (l >= S && r <= E) {
      tr[idx].mx++;
      tr[idx].tag++;
    } else {
      int mid = l + r >> 1;
      if (mid >= S) update(S, E, l, mid, idx << 1);
      if (E > mid) update(S, E, mid + 1, r, idx << 1 | 1);
      tr[idx].mx = tr[idx].tag + max(tr[idx << 1].mx, tr[idx << 1 | 1].mx);
    }
  }

  int book(int start, int end) {
    update(start, end - 1, 0, 1e9, 1);
    return tr[1].mx;
  }
};
#endif