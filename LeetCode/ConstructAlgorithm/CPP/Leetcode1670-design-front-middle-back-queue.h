#include <deque>

using namespace std;

// 两个deque，保证第一个deque的size比第二个deque大1或者相等

class FrontMiddleBackQueue {
 public:
  deque<int> l, r;
  FrontMiddleBackQueue() {}

  void pushleft() {
    if (r.size() > l.size()) {
      auto cur = r.front();
      r.pop_front();
      l.push_back(cur);
    }
  }

  void pushright() {
    if (l.size() > r.size() + 1) {
      auto cur = l.back();
      l.pop_back();
      r.push_front(cur);
    }
  }

  void pushFront(int val) {
    l.push_front(val);
    pushright();
  }

  void pushMiddle(int val) {
    if (l.empty() && r.empty()) {
      l.push_back(val);
      return;
    }
    if (l.size() == r.size()) {
      l.push_back(val);
      return;
    }
    auto cur = l.back();
    l.pop_back(), r.push_front(cur);
    l.push_back(val);
  }

  void pushBack(int val) {
    r.push_back(val);
    pushleft();
  }

  int popFront() {
    if (l.empty() && r.empty()) {
      return -1;
    }
    auto res = l.front();
    l.pop_front();
    pushleft();
    return res;
  }

  int popMiddle() {
    if (l.empty() && r.empty()) {
      return -1;
    }
    auto res = l.back();
    l.pop_back();
    pushleft();
    return res;
  }

  int popBack() {
    if (l.empty() && r.empty()) {
      return -1;
    }
    if (r.empty()) {
      auto res = l.back();
      l.pop_back();
      return res;
    }
    auto res = r.back();
    r.pop_back();
    pushright();
    return res;
  }
};
