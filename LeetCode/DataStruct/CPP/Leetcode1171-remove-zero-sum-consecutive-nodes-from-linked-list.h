#include <unordered_map>

using namespace std;

// 记录一个前缀和，如果重复出现说明有一段区间为0，删掉

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* removeZeroSumSublists(ListNode* head) {
    unordered_map<int, ListNode*> mp;
    auto* dummy = new ListNode(0);
    dummy->next = head;
    mp[0] = dummy;
    int sum = 0;
    for (auto p = head; p; p = p->next) {
      sum += p->val;
      if (mp.count(sum)) {
        int cur = sum;
        for (auto* q = mp[sum]->next; q != p; q = q->next) {
          cur += q->val;
          mp.erase(cur);
        }
        mp[sum]->next = p->next;
      } else {
        mp[sum] = p;
      }
    }
    head = dummy->next;
    delete dummy;
    return head;
  }
};
