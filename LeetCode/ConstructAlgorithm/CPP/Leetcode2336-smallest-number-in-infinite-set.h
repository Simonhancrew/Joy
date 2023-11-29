#include <unordered_set>
#include <queue>

using namespace std;

class SmallestInfiniteSet {
 public:
  unordered_set<int> st;
  priority_queue<int, vector<int>, greater<int>> q;
  SmallestInfiniteSet() {
    for (int i = 1; i <= 1000; i++) {
      st.insert(i);
      q.push(i);
    }
  }

  int popSmallest() {
    auto t = q.top();
    st.erase(t);
    q.pop();
    return t;
  }

  void addBack(int num) {
    if (st.count(num)) {
      return;
    }
    st.insert(num);
    q.push(num);
  }
};
