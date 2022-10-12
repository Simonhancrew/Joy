#include <unordered_set>

using std::unordered_set;
using std::vector;

class Solution {
 public:
  int numComponents(ListNode *head, vector<int> &nums) {
    unordered_set<int> st{nums.begin(), nums.end()};
    bool in = false;
    int res = 0;
    while (head) {
      if (st.count(head->val)) {
        if (!in) {
          in = true;
          ++res;
        }
      } else {
        in = false;
      }
      head = head->next;
    }
    return res;
  }
};