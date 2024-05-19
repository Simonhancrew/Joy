#include <vector>

using namespace std;

// 本质在求，因为小的数会被移到最后，遍历到的最大值一定是尾后增加的数要大的
// 遍历过程中求首个连续k回合都是最大值的数，如果遍历结束了数组还没找到这样的值
// 说明最大值就是要求的答案

class Solution {
public:
  int getWinner(vector<int> &arr, int k) {
    int ans = arr[0], cnt = 0;
    int n = arr.size();
    for (int i = 1; i < n && cnt < k; i++) {
      if (arr[i] > ans) {
        ans = arr[i];
        cnt = 0;
      }
      cnt++;
    }
    return ans;
  }
};
