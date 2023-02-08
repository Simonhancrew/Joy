#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

struct Trie {
  int idx = -1;
  unordered_map<string, Trie*> child;
};

class Solution {
public:
  vector<string> split(const string& s) {
    vector<string> ans;
    string cur;
    for (const auto& c : s) {
      if (c == '/') {
        ans.push_back(move(cur));
      } else {
        cur += c;
      }
    }
    ans.push_back(move(cur));
    return ans;
  }
  vector<string> ans;
  vector<string> folder;
  void dfs(Trie* root) {
    if (root->idx != -1) {
      ans.push_back(folder[root->idx]);
      return;
    }
    for(const auto& [k, v] : root->child) {
      dfs(v);
    }
  }
  vector<string> removeSubfolders(vector<string>& folder) {
    Trie* root = new Trie();
    this->folder = folder;
    int n = folder.size();
    for (int i = 0;i < n;i++) {
      auto fd = folder[i];
      auto dir = split(fd);
      Trie* cur = root;
      for (const auto& x : dir) {
        if (!cur->child.count(x)) {
          cur->child[x] = new Trie();
        }
        cur = cur->child[x];
      }
      cur->idx = i;
    }
    dfs(root);
    return ans;
  }
};
