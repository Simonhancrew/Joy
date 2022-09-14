const int N = 3e4 + 10;
int son[N][26], idx;
int id[N];

/*
    trie插入，随后在书中做一个查找，有分支则继续深搜
    顺序查找的时候肯定字典序最小，返回的时候带长度做比较就行了
*/

class Solution {
 public:
  void insert(string &word, int idc) {
    int p = 0;
    for (auto &ch : word) {
      int t = ch - 'a';
      if (!son[p][t]) son[p][t] = ++idx;
      p = son[p][t];
    }
    id[p] = idc;
  }

  vector<int> dfs(int p, int len) {
    vector<int> res{len, id[p]};
    for (int i = 0; i < 26; i++) {
      int j = son[p][i];
      if (j && id[j] != -1) {
        auto t = dfs(j, len + 2);
        if (res[0] < t[0]) res = t;
      }
    }
    return res;
  }
  string longestWord(vector<string> &words) {
    memset(son, 0, sizeof son);
    memset(id, -1, sizeof id);
    idx = 0;
    for (int i = 0; i < words.size(); i++) insert(words[i], i);

    auto t = dfs(0, 0);
    if (t[1] != -1) return words[t[1]];
    return "";
  }
};