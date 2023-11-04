#include <vector>

using namespace std;

struct node {
  // left 1, rigth 0
  node *left{}, *right{};
};

class Tr {
 public:
  Tr() : head_(new node()) { vec_.push_back(head_); }

  ~Tr() {
    for (const auto *x : vec_) {
      delete x;
    }
  }

  Tr(const Tr &) = delete;
  Tr &operator=(const Tr &) = delete;

  void insert(int x) {
    auto *it = head_;
    for (int i = 30; i >= 0; i--) {
      auto cur = (x >> i) & 1;
      if (cur == 1) {
        if (!it->left) {
          it->left = new node();
          vec_.push_back(it->left);
        }
        it = it->left;
      } else {
        if (!it->right) {
          it->right = new node();
          vec_.push_back(it->right);
        }
        it = it->right;
      }
    }
  }

  int query(int x) {
    auto *it = head_;
    int tar = 0;
    for (int i = 30; i >= 0; i--) {
      auto cur = (x >> i) & 1;
      if (cur == 1) {
        if (it->right) {
          tar = tar * 2 + 0;
          it = it->right;
        } else {
          tar = tar * 2 + 1;
          it = it->left;
        }
      } else {
        if (it->left) {
          tar = tar * 2 + 1;
          it = it->left;
        } else {
          tar = tar * 2;
          it = it->right;
        }
      }
    }
    return x ^ tar;
  }

 private:
  node *head_{};
  vector<node *> vec_;
};

class Solution {
 public:
  static int findMaximumXOR(vector<int> &nums) {
    Tr tr;
    for (const auto x : nums) {
      tr.insert(x);
    }
    int ans = 0;
    for (const auto x : nums) {
      auto cur = tr.query(x);
      ans = max(ans, cur);
    }
    return ans;
  }
};
