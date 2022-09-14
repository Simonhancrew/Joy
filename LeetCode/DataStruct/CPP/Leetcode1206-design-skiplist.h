/*
    一个跳表的实现
*/

static const int kMaxLevel = 8;

struct Node {
  int val_;
  vector<Node *> next_;
  Node(int val) : val_(val), next_(kMaxLevel, nullptr) {}
};

class Skiplist {
 public:
  Node *head_;
  Skiplist() { head_ = new Node(-1); }

  vector<Node *> find(int target) {
    vector<Node *> pre(kMaxLevel, nullptr);
    auto p = head_;
    for (int i = kMaxLevel - 1; i >= 0; i--) {
      while (p->next_[i] && p->next_[i]->val_ < target) p = p->next_[i];
      pre[i] = p;
    }
    return pre;
  }

  bool search(int target) {
    auto pre = find(target);
    auto p = pre[0]->next_[0];
    return p && p->val_ == target;
  }

  void add(int num) {
    auto pre = find(num);
    auto p = new Node(num);
    for (int i = 0; i < kMaxLevel; i++) {
      p->next_[i] = pre[i]->next_[i];
      pre[i]->next_[i] = p;
      if (rand() % 2) break;
    }
  }

  bool erase(int num) {
    auto pre = find(num);
    auto p = pre[0]->next_[0];
    if (!p || p->val_ != num) return false;

    for (int i = 0; i < kMaxLevel && pre[i]->next_[i] == p; i++) {
      pre[i]->next_[i] = p->next_[i];
    }
    delete p;
    return true;
  }
};