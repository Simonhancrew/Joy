#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> secondGreaterElement(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    vector<int> s, t;
    for (int i = 0; i < n; i++) {
      int cur = nums[i];
      while (!t.empty() && nums[t.back()] < cur) {
        res[t.back()] = cur;
        t.pop_back();
      }
      int j = s.size();
      while (j && nums[s[j - 1]] < cur) {
        j--;
      }
      t.insert(t.end(), s.begin() + j, s.end());
      s.resize(j);
      s.push_back(i);
    }
    return res;
  }
};
