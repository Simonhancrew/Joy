#include <queue>

using namespace std;

// 按照结束时间排序，看[a1, b1], [a2, b2], 如果a1 + a2 <= b1, 怎么安排这两门课都没事
// 如果a1 + a2 > b1 && a1 + a2 <= b2，先要上a1,然后上c2
// 如果a1 + a2 > b2, 说明只能上一门课
// 针对某次t + a1 > b2, 去掉耗时最长的，因为此时已经按照ddl排好序，自己ddl更大，如果耗时更长的不是自己，则此时我一定是更优解
// 保证前面的用时最小，后面的duration才有更大的可能性满足ddl

class Solution {
 public:
  int scheduleCourse(vector<vector<int>>& courses) {
    sort(courses.begin(), courses.end(),
         [](const auto& lhs, const auto& rhs) { return lhs[1] < rhs[1]; });
    priority_queue<int> heap;
    int tot = 0;
    int n = courses.size();
    for (int i = 0; i < n; i++) {
      if (tot + courses[i][0] <= courses[i][1]) {
        tot += courses[i][0];
        heap.push(courses[i][0]);
      } else if (heap.size()) {
        auto t = heap.top();
        if (t > courses[i][0]) {
          tot = tot - t + courses[i][0];
          heap.pop();
          heap.push(courses[i][0]);
        }
      }
    }
    return heap.size();
  }
};
