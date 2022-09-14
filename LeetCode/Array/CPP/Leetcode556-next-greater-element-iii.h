/*
    逆向找到不是递减的idx，然后和后续大于当前那s[idx]的数交换
    最后reverse(idx + 1,end)
*/
class Solution {
 public:
  int nextGreaterElement(int n) {
    string s = to_string(n);
    int i = s.size() - 1;
    while (i && s[i - 1] >= s[i]) i--;
    if (!i) return -1;
    int j = i;
    while (j + 1 < s.size() && s[j + 1] > s[i - 1]) j++;
    swap(s[j], s[i - 1]);
    reverse(s.begin() + i, s.end());
    long long ans = stoll(s);
    if (ans > INT_MAX) return -1;
    return ans;
  }
};