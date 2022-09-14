#include <vector>

/*
    本来只需要开k大小的数组，但是比较难标识什么时候数组满了。
    因为此时满了也是hh == tt.所以不如多开一个错开，tt + 1 == hh的时候数组是满的
    tt - 1是实际的队尾。整体看作一个连成的环，因此所有的值需要去一个mod
*/

using std::vector;

class MyCircularDeque {
 public:
  int hh = 0, tt = 0;
  vector<int> buf;
  MyCircularDeque(int k) {
    buf.resize(k + 1);
    hh = 0, tt = 0;
  }

  int get(int x) { return (x + buf.size()) % buf.size(); }

  bool insertFront(int value) {
    if (isFull()) return false;
    hh = get(hh - 1);
    buf[hh] = value;
    return true;
  }

  bool insertLast(int value) {
    if (isFull()) return false;
    buf[tt] = value;
    tt = get(tt + 1);
    return true;
  }

  bool deleteFront() {
    if (isEmpty()) return false;
    hh = get(hh + 1);
    return true;
  }

  bool deleteLast() {
    if (isEmpty()) return false;
    tt = get(tt - 1);
    return true;
  }

  int getFront() {
    if (isEmpty()) return -1;
    return buf[hh];
  }

  int getRear() {
    if (isEmpty()) return -1;
    return buf[get(tt - 1)];
  }

  bool isEmpty() { return hh == tt; }

  bool isFull() { return get(tt + 1) == hh; }
};