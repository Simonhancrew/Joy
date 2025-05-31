class Solution {
 public:
  using PII = pair<int, int>;
  int snakesAndLadders(vector<vector<int>> &board) {
    int n = board.size();
    vector<bool> st(n * n + 1, false);
    queue<PII> q;
    st[1] = true;
    q.push({1, 0});
    while (!q.empty()) {
      auto [node, d] = q.front();
      q.pop();
      if (node == n * n) {
        return d;
      }
      for (int i = 1; i <= 6; ++i) {
        int next = node + i;
        if (next > n * n) {
          continue;
        }
        int r = (next - 1) / n, c = (next - 1) % n;
        if (r % 2 == 1) {
          c = n - 1 - c;  // Reverse column index for odd rows
        }
        if (board[n - 1 - r][c] != -1) {
          next = board[n - 1 - r]
                      [c];  // Move to the destination of snake or ladder
        }
        if (!st[next]) {
          st[next] = true;
          q.push({next, d + 1});
        }
      }
    }
    return -1;
  }
};
