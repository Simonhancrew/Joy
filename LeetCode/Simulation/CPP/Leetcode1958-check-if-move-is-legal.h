#include <vector>

using namespace std;

class Solution {
public:
  static constexpr int dx[8] = {0, 1, 0, -1, -1, 1, 1, -1};
  static constexpr int dy[8] = {1, 0, -1, 0, 1, 1, -1, -1};
  bool checkMove(vector<vector<char>> &board, int rMove, int cMove,
                 char color) {
    for (int i = 0; i < 8; i++) {
      int x = rMove + dx[i], y = cMove + dy[i];
      if (x < 0 || y < 0 || x >= 8 || y >= 8 || board[x][y] == '.' ||
          board[x][y] == color) {
        continue;
      }
      while (true) {
        x += dx[i];
        y += dy[i];
        if (x < 0 || y < 0 || x >= 8 || y >= 8 || board[x][y] == '.') {
          break;
        }
        if (board[x][y] == color) {
          return true;
        }
      }
    }
    return false;
  }
};
