#include <queue>

using namespace std;

class MyStack {
public:
  void push(int x) {
    b.push(x);
    while (!a.empty()) {
      auto p = a.front();
      a.pop();
      b.push(p);
    }
    a = std::move(b);
  }

  int pop() {
    auto res = a.front();
    a.pop();
    return res;
  }

  int top() { return a.front(); }

  bool empty() const { return a.empty(); }

  queue<int> a;
  queue<int> b;
};
