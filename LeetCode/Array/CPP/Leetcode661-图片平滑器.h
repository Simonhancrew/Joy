class Solution {
 public:
  int n, m;
  int get(int x, int y, vector<vector<int>> const& img) {
    int acc = 0, div = 0;
    for (int i = -1; i <= 1; i++) {
      for (int j = -1; j <= 1; j++) {
        int nx = x + i, ny = y + j;
        if (nx >= n || nx < 0 || ny >= m || ny < 0)
          continue;
        else
          acc += img[nx][ny], div++;
      }
    }
    if (!div) return 0;
    return acc / div;
  }
  vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    n = img.size(), m = img[0].size();
    vector<vector<int>> res(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        res[i][j] = get(i, j, img);
        // cout << res[i][j] << endl;
      }
    }
    return res;
  }
};