#include <algorithm>
#include <set>
#include <vector>

using namespace std;

const int INF = 1e9 + 10;
using PII = pair<int, int>;

#define x first
#define y second

class RangeModule {
 public:
  set<PII> st;
  RangeModule() {
    st.insert({INF, INF});
    st.insert({-INF, -INF});
  }

  void addRange(int left, int right) {
    auto it = st.lower_bound({left, -INF});
    it--;
    if (it->y < left) it++;
    if (it->x > right)
      st.insert({left, right});
    else {
      auto j = it;
      while (j->x <= right) j++;
      j--;
      PII t({min(left, it->x), max(right, j->y)});
      while (it != j) {
        auto k = it;
        k++;
        st.erase(it);
        it = k;
      }
      st.erase(it);
      st.insert(t);
    }
  }

  bool queryRange(int left, int right) {
    auto it = st.upper_bound({left, INF});
    it--;
    return it->y >= right;
  }

  vector<PII> get(PII a, PII b) {
    vector<PII> res;
    if (a.x < b.x) {
      if (a.y > b.y) {
        res.push_back({a.x, b.x});
        res.push_back({b.y, a.y});
      } else {
        res.push_back({a.x, b.x});
      }
    } else {
      if (a.y > b.y) res.push_back({b.y, a.y});
    }
    return res;
  }

  void removeRange(int left, int right) {
    auto it = st.lower_bound({left, -INF});
    it--;
    if (it->y < left) it++;
    if (it->x <= right) {
      auto j = it;
      while (j->x <= right) j++;
      j--;

      auto a = get(*it, {left, right});
      auto b = get(*j, {left, right});

      while (it != j) {
        auto k = it;
        k++;
        st.erase(it);
        it = k;
      }
      st.erase(it);
      for (auto t : a) st.insert(t);
      for (auto t : b) st.insert(t);
    }
  }
};