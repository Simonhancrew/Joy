#include <string>

using namespace std;

class trie {
 public:
  trie() : flag(false) {
    for (int i = 0; i < 26; i++) son[i] = nullptr;
  }
  void insert(string s) {
    auto node = this;
    for (int i = 0; i < s.size(); i++) {
      int id = s[i] - 'a';
      if (!node->son[id]) node->son[id] = new trie();
      node = node->son[id];
    }
    node->flag = true;
  }

  int query(string s) {
    auto node = this;
    for (int i = 0; i < s.size(); i++) {
      int id = s[i] - 'a';
      if (!node->son[id]) return s.size();
      node = node->son[id];
      if (node->flag) return i + 1;
    }
    return s.size();
  }
  trie *son[26];
  bool flag;
};

class Solution {
 public:
  trie *root;
  string replaceWords(vector<string> &dictionary, string sentence) {
    root = new trie();
    for (auto s : dictionary) root->insert(s);
    string res;
    for (int i = 0; i < sentence.size(); i++) {
      int k = i;
      while (k < sentence.size() && sentence[k] != ' ') k++;
      string t = sentence.substr(i, k - i);
      int idx = root->query(t);
      res += t.substr(0, idx) + ' ';
      i = k;
    }
    res.pop_back();
    return res;
  }
};