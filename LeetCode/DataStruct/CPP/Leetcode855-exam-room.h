#include <functional>
#include <set>
#include <unordered_map>


using namespace std;


// 同849, 新的就坐点，要么是区间的左右边界，要么是两个人坐了的中间，看看那个距离更大
// 利用平衡树维护可以坐的区间大小（坐中间），针对边界区间特殊处理（坐边界）

class ExamRoom {
 public:
  ExamRoom(int n) : n(n), st(cmp(n)) {
    add({-1, n});
  }

  int seat() {
    auto s      = *st.begin();
    auto [l, r] = s;
    auto p      = (l + r) >> 1;
    if (l == -1) {
      p = 0;
    } else if (r == n) {
      p = n - 1;
    }
    del(s);
    add({l, p});
    add({p, r});
    return p;
  }

  void leave(int p) {
    auto l = lhs[p];
    auto r = rhs[p];
    del({l, p});
    del({p, r});
    add({l, r});
  }

 private:
  using PII = pair<int, int>;

  void add(const PII &p) {
    st.insert(p);
    auto [l, r] = p;
    lhs[r]      = l;
    rhs[l]      = r;
  }

  void del(const PII &p) {
    st.erase(p);
    auto [l, r] = p;
    lhs.erase(r);
    rhs.erase(l);
  }

  int n;

  static std::function<bool(const PII &, const PII &)> cmp(int n) {
    auto dis = [n](const PII &p) {
      auto [l, r] = p;
      if (l == -1 || r == n) {
        return r - l - 1;
      }
      return (r - l) >> 1;
    };
    return [dis](const auto &l, const auto &r) {
      int dl = dis(l), dr = dis(r);
      return dl == dr ? l.first < r.first : dl > dr;
    };
  }

  set<PII, decltype(cmp(n))> st;
  unordered_map<int, int> lhs;
  unordered_map<int, int> rhs;
};
