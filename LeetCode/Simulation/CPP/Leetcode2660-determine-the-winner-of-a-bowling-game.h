#include <vector>

using namespace std;

class Solution {
 public:
  int isWinner(vector<int>& player1, vector<int>& player2) {
    static auto calcu = [](const vector<int>& arr) {
      int n = arr.size();
      int acc = 0;
      for (int i = 0; i < n; i++) {
        auto flag =
            (i >= 1 && arr[i - 1] == 10) || (i >= 2 && arr[i - 2] == 10);
        if (flag) {
          acc += 2 * arr[i];
        } else {
          acc += arr[i];
        }
      }
      return acc;
    };
    auto a1 = calcu(player1);
    auto a2 = calcu(player2);
    if (a1 == a2) {
      return 0;
    }
    if (a1 > a2) {
      return 1;
    }
    return 2;
  }
};
