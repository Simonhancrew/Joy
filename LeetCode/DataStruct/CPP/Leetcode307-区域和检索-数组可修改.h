/*
    树状数组存原数组
*/
class NumArray {
 public:
  vector<int> tr;
  int n;
  NumArray(vector<int>& nums) {
    n = nums.size();
    tr.resize(n + 1);
    for (int i = 1; i <= n; i++) add(i, nums[i - 1]);
  }

  void update(int index, int val) {
    int pre = ask(index + 1) - ask(index), after = val;
    int ch = val - pre;
    add(index + 1, ch);
  }

  int sumRange(int left, int right) { return ask(right + 1) - ask(left); }

  int lowbit(int x) { return x & -x; }

  void add(int x, int k) {
    for (int i = x; i <= n; i += lowbit(i)) {
      tr[i] += k;
    }
  }

  int ask(int x) {
    int sum = 0;
    for (int i = x; i; i -= lowbit(i)) {
      sum += tr[i];
    }
    return sum;
  }
};