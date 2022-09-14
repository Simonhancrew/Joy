class RecentCounter {
 public:
  queue<int> q;
  RecentCounter() {}

  int ping(int t) {
    q.push(t);
    while (t - q.front() > 3000) q.pop();
    return q.size();
  }
};
