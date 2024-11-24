#include <queue>
#include <vector>


using namespace std;

/*
  NOTE:
    持续看最左侧的范围，然后逐步弹出最小的数继续看下一个范围
    比如:
      [2, 3, 4, 10]
      [0, 1, 2, 11]
      [3, 4, 9]
    先看[0, 2, 3], 算出第一个范围
    然后不看之前最小左侧，算下一轮
      [2, 3, 4, 10]
      [1, 2, 11]
      [3, 4, 9]
    继续算最左侧
*/

class Solution {
 public:
  vector<int> smallestRange(vector<vector<int>> &nums) {
    priority_queue<vector<int>, vector<vector<int>>, greater<>> heap;
    int r = -1e5;
    for (int i = 0; i < nums.size(); i++) {
      heap.push({nums[i][0], i, 0});
      r = max(r, nums[i][0]);
    }
    int ans_l = heap.top()[0];
    int ans_r = r;
    while (!heap.empty()) {
      auto tmp = heap.top();
      int i = tmp[1], j = tmp[2];
      if (j + 1 >= nums[i].size()) {
        break;
      }
      heap.pop();
      heap.push({nums[i][j + 1], i, j + 1});
      r     = max(r, nums[i][j + 1]);
      int l = heap.top()[0];
      if (r - l < ans_r - ans_l) {
        ans_l = l;
        ans_r = r;
      }
    }
    return {ans_l, ans_r};
  }
};
