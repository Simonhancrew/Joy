#include <unordered_map>

using namespace std;

class LRUCache {
 public:
  struct node {
    int val{}, key{-1};
    node *next{}, *pre{};
    explicit node(int val) : val(val) {}
  };
  int size_{}, cap_{};
  unordered_map<int, node*> mp;
  node *dummy_{}, *tail_{};
  explicit LRUCache(int capacity)
      : cap_(capacity), dummy_(new node(-1)), tail_(new node(-1)) {
    dummy_->next = tail_;
    tail_->pre = dummy_;
  }

  int get(int key) {
    if (mp.count(key) == 0) {
      return -1;
    }
    auto* node = mp.at(key);
    ReRank(node);
    return node->val;
  }

  void ReRank(node* node) const {
    if (dummy_->next != node) {
      node->pre->next = node->next;
      node->next->pre = node->pre;
      node->next = dummy_->next;
      node->pre = dummy_;
      dummy_->next->pre = node;
      dummy_->next = node;
    }
  }

  void InsertHead(node* node) const {
    auto* ne = dummy_->next;
    ne->pre = node;
    node->next = ne;
    node->pre = dummy_;
    dummy_->next = node;
  }

  void RemoveTail() {
    auto* pre = tail_->pre;
    mp.erase(pre->key);
    pre->pre->next = tail_;
    tail_->pre = pre->pre;
    --size_;
    delete pre;
  }

  void put(int key, int value) {
    if (mp.count(key) != 0) {
      auto* node = mp.at(key);
      node->val = value;
      ReRank(node);
      return;
    }
    if (size_ + 1 > cap_) {
      RemoveTail();
    }
    auto* new_node = new node(value);
    new_node->key = key;
    mp[key] = new_node;
    InsertHead(new_node);
    ++size_;
  }
};
