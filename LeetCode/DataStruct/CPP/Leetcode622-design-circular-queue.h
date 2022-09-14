class MyCircularQueue {
 public:
  vector<int> q;
  int hh, tt;
  MyCircularQueue(int k) {
    hh = tt = 0;
    q.resize(k + 1);
  }

  bool enQueue(int value) {
    if (isFull()) return false;
    q[tt++] = value;
    if (tt == q.size()) tt = 0;
    return true;
  }

  bool deQueue() {
    if (isEmpty()) return false;
    hh++;
    if (hh == q.size()) hh = 0;
    return true;
  }

  int Front() {
    if (isEmpty()) return -1;
    return q[hh];
  }

  int Rear() {
    if (isEmpty()) return -1;
    int t = tt - 1;
    if (t < 0) t += q.size();
    return q[t];
  }

  bool isEmpty() { return hh == tt; }

  bool isFull() { return (tt + 1) % q.size() == hh; }
};