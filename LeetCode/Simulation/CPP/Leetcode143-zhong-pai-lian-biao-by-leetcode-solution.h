#include <vector>

using namespace std;

class Solution {
 public:
  void reorderList(ListNode* head) {
    vector<ListNode*> rec;
    auto* node = head;
    while (node) {
      rec.push_back(node);
      node = node->next;
    }
    int n = rec.size();
    vector<ListNode*> ans;
    for (int i = 0, j = n - 1; i <= j; i++, j--) {
      ans.push_back(rec[i]);
      if (i != j) ans.push_back(rec[j]);
    }
    head = ans[0];
    for (int i = 0; i < n - 1; i++) {
      if (!ans[i]) cout << i << endl;
      ans[i]->next = ans[i + 1];
      ans[i + 1]->next = nullptr;
    }
  }
};
