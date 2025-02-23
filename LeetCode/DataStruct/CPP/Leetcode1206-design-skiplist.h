/*
    一个跳表的实现
*/

static const int kMaxLevel = 8;

struct Node {
  int val_;
  vector<Node *> next_;
  Node(int val) : val_(val), next_(kMaxLevel, nullptr) {
  }
};

class Skiplist {
 public:
  Node *head_;
  Skiplist() {
    head_ = new Node(-1);
  }

  vector<Node *> find(int target) {
    vector<Node *> pre(kMaxLevel, nullptr);
    auto p = head_;
    for (int i = kMaxLevel - 1; i >= 0; i--) {
      while (p->next_[i] && p->next_[i]->val_ < target)
        p = p->next_[i];
      pre[i] = p;
    }
    return pre;
  }

  bool search(int target) {
    auto pre = find(target);
    auto p   = pre[0]->next_[0];
    return p && p->val_ == target;
  }

  void add(int num) {
    auto pre = find(num);
    auto p   = new Node(num);
    for (int i = 0; i < kMaxLevel; i++) {
      p->next_[i]      = pre[i]->next_[i];
      pre[i]->next_[i] = p;
      if (rand() % 2)
        break;
    }
  }

  bool erase(int num) {
    auto pre = find(num);
    auto p   = pre[0]->next_[0];
    if (!p || p->val_ != num)
      return false;

    for (int i = 0; i < kMaxLevel && pre[i]->next_[i] == p; i++) {
      pre[i]->next_[i] = p->next_[i];
    }
    delete p;
    return true;
  }
};

/*
  NOTE:
    等价一个多层链表，0层是全量信息。每一层是之前一层的稀疏节点，会丢失部分之前的节点，
    这样的好处是从上层节点往下找的时候能跳过很多没必要的节点，跳的核心就在这里，怎么实现就随意了，但是肯定是打不过STL的
*/
#if 0

struct SkipListNode {
  int key;
  int val;
  vector<SkipListNode *> next;
  SkipListNode(int key, int val, int lv = 0, SkipListNode *ne = nullptr)
      : key(key), val(val), next(lv, ne) {}
  void print() {
    auto p = next[0];
    while (!p->next.empty()) {
        cout << p->key << ": " << p->key << "-->";
        p = p->next[0];
    }
    cout << '\n';
  }
};

class Skiplist {
public:
  int current_level_ = 0;
  SkipListNode *head_;
  SkipListNode *tail_;
  static constexpr int kMaxLevel = 32;
  Skiplist() {
    tail_ = new SkipListNode(INT_MAX, 0);
    head_ = new SkipListNode(INT_MAX, 0, kMaxLevel + 1, tail_);
  }
  ~Skiplist() {
    while (head_) {
        auto ne = head_->next[0];
        delete head_;
        if (ne == tail_) {
            break;
        } 
        head_ = ne;
    }
  }

  bool search(int target) {
    auto *node = head_;
    for (int i = current_level_; i >= 0; i--) {
      while (node->next[i]->key < target) {
        node = node->next[i];
      }
    }
    auto *p = node->next[0];
    return p->key == target;
  }

  int RandLevel() {
    static constexpr int P = 4;
    static constexpr int S = 0xFFFF;
    static constexpr int PS = S / P;
    int lv = 1;
    while ((rand() & S) < PS)
      ++lv;
    return kMaxLevel > lv ? lv : kMaxLevel;
  }

  void add(int num) {
    auto *node = head_;
    vector<SkipListNode *> update(kMaxLevel + 1, nullptr);
    for (int i = current_level_; i >= 0; i--) {
      while (node->next[i]->key < num) {
        node = node->next[i];
      }
      update[i] = node;
    }
    auto *p = node->next[0];
    if (p->key == num) {
      p->val++;
      return;
    }
    auto rand_level = RandLevel();
    if (rand_level > current_level_) {
      current_level_++;
      update[current_level_] = head_;
    }
    auto *new_node = new SkipListNode(num, 1, kMaxLevel + 1, NULL);
    for (int i = current_level_; i >= 0; i--) {
      new_node->next[i] = update[i]->next[i];
      update[i]->next[i] = new_node;
    }
  }

  bool erase(int num) {
    auto *node = head_;
    vector<SkipListNode *> update(kMaxLevel + 1, nullptr);
    for (int i = current_level_;i >= 0;i--) {
      while (node->next[i]->key < num) {
        node = node->next[i];
      }
      update[i] = node;
    }
    auto *p = node->next[0];
    if (p->key != num) {
      return false;
    }
    p->val--;
    if (p->val == 0) {
      for (int i = 0;i <= current_level_;i++) {
        if (update[i]->next[i] != p) {
          break;
        }
        update[i]->next[i] = p->next[i];
      }
      delete p;
      while (current_level_ > 0 && head_->next[current_level_] == tail_) {
        current_level_--;
      }
    }
    return true;
  }
};
#endif