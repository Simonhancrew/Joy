#include <vector>

using namespace std;

class StockSpanner {
 public:
  using PII = pair<int, int>;
  vector<PII> st;
  int idx{};

  StockSpanner() = default;

  int next(int price) {
    while (!st.empty() && st.back().second <= price) {
      st.pop_back();
    }
    if (st.empty()) {
      st.emplace_back(idx++, price);
      return idx;
    }
    int id = st.back().first;
    auto res = idx - id;
    st.emplace_back(idx++, price);
    return res;
  }
};
