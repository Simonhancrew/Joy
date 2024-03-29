#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> mp = {"Sunday",   "Monday", "Tuesday", "Wednesday",
                       "Thursday", "Friday", "Saturday"};
  int whatday(int d, int m, int y) {
    int ans;
    if (m == 1 || m == 2) {
      m += 12, y--;
    }
    if (y < 1752 || (y == 1752 && m < 9) || (y == 1752 && m == 9 && d < 3)) {
      ans = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 + 5) % 7;
    } else {
      ans = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;
    }
    return ans;
  }
  string dayOfTheWeek(int day, int month, int year) {
    return mp[(whatday(day, month, year) + 1) % 7];
  }
};
