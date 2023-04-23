class Solution {
 public:
  vector<int> f;
  vector<vector<int>> books;
  int shelfWidth;
  int dfs(int x) {
    if (x < 0) return 0;
    if (f[x] != -1) return f[x];
    int& res = f[x];
    res = INT_MAX;
    int s = 0, h = 0;
    for (int i = x; i >= 0; i--) {
      s += books[i][0];
      if (s > shelfWidth) break;
      h = max(h, books[i][1]);
      res = min(res, dfs(i - 1) + h);
    }
    return res;
  }
  int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    this->books = std::move(books);
    this->shelfWidth = shelfWidth;
    int n = this->books.size();
    f.resize(n, -1);
    return dfs(n - 1);
  }
};
