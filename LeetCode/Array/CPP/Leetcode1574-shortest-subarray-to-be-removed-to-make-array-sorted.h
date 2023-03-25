// 这种求单调不减 + 移除部分的问题， 一般最后的结果数组
// 都可以看作是前缀 + 后缀的组合， 其中前缀和后缀都要是单调不减的
// 因此， 维护一个不重合的前缀[0, i], 一个后缀[j, n]， i < j(取不到等号)
// 其中， 前或后缀可以是空的
class Solution {
 public:
  int findLengthOfShortestSubarray(vector<int>& arr) {
    int n = arr.size();
    int j = n - 1;
    while (j > 0 && arr[j] >= arr[j - 1]) {
      j--;
    }
    int len = n - j;
    for (int i = 0; i < n; i++) {
      if (i > 0 && arr[i] < arr[i - 1]) {
        break;
      }
      while (i >= j || j < n && arr[i] > arr[j]) {
        ++j;
      }
      len = max(len, i + 1 + n - j);
    }
    return n - len;
  }
};