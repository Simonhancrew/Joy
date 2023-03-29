#include <iostream>

using namespace std;

// 算一下每个月第一天到1900/01/01的日期间隔days， 每个月13号就是（days + 12） %
// 7, 闰年的2月多算一天。总体按年枚举然后枚举月

const int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int weekday[7];
int n;

int main() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin >> n;
  int year = 1900, days = 0;
  while (n--) {
    for (int i = 1; i <= 12; i++) {
      weekday[(days + 12) % 7]++;
      days += months[i];
      if (i == 2) {
        if (year % 4 == 0 && year % 100 || year % 400 == 0) {
          days++;
        }
      }
    }
    year++;
  }
  for (int i = 5, j = 0; j < 7; i++, j++) {
    cout << weekday[i % 7] << ' ';
  }
  return 0;
}