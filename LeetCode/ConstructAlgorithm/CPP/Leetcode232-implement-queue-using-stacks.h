#include <stack>

using namespace std;

class MyQueue {
public:
  MyQueue() {}

  static void Consume(stack<int> &a, stack<int> &b) {
    while (!a.empty()) {
      auto t = a.top();
      b.push(t);
      a.pop();
    }
  }

  void push(int x) {
    stack<int> b;
    Consume(a, b);
    a.push(x);
    Consume(b, a);
  }

  int pop() {
    auto res = a.top();
    a.pop();
    return res;
  }

  int peek() { return a.top(); }

  bool empty() { return a.empty(); }
  stack<int> a;
};
