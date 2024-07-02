#include <array>
#include <unordered_set>

using namespace std;

class Solution {
public:
  array<bool, 101> rec;
  unordered_set<int> st;

  Solution() {
    for (int i = 2; i <= 100; i++) {
      if (rec[i])
        continue;
      st.insert(i);
      for (int j = i; j <= 100; j += i) {
        rec[j] = true;
      }
    }
  }

  int maximumPrimeDifference(vector<int> &nums) {
    int n = nums.size();
    int i = 0, j = n - 1;
    while (i < n && !st.count(nums[i]))
      i++;
    while (j >= i && !st.count(nums[j]))
      j--;
    return j - i;
  }
};
