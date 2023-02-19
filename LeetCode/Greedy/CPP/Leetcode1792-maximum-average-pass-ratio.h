// 贪心， 要让能通过的学生尽量去潜力大的班级
// 每去一个的提升是b + 1 / a + 1 - b / a = a - b / a * (a + 1)
// a越大， 提升越小， 所以动态的开一个大堆做就行， 按照提升大小排序
class Solution {
 public:
  struct Node {
    int a, b;
    double v;
    bool operator<(const Node& l) const { return v < l.v; }
  };
  double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    priority_queue<Node> heap;
    double sum = 0;
    for (const auto c : classes) {
      Node cur;
      cur.a = c[1], cur.b = c[0];
      sum += (double)cur.b / cur.a;
      cur.v = (cur.a - cur.b) / (cur.a * (cur.a + 1.0));
      heap.push(cur);
    }

    while (extraStudents--) {
      auto t = heap.top();
      heap.pop();
      sum += t.v;
      t.a += 1, t.b += 1, t.v = (t.a - t.b) / (t.a * (t.a + 1.0));
      heap.push(t);
    }
    return sum / classes.size();
  }
};