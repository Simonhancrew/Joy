#pragma once

#include <array>
#include <functional>
#include <string>


using namespace std;
class Solution {
 public:
  int countTime(string time) {
    int mx = 23 * 60 + 59;
    array<int, 4> d{600, 60, 10, 1};
    array<int, 4> p{2, 9, 5, 9};
    time = time.substr(0, 2) + time.substr(3);
    int ans = 0;
    std::function<void(int, int)> dfs = [&](int idx, int acc) {
      if (idx == 4) {
        if (acc <= mx) ans++;
        return;
      }
      if (time[idx] == '?') {
        for (int i = 0; i <= p[idx]; i++) {
          acc += d[idx] * i;
          dfs(idx + 1, acc);
          acc -= d[idx] * i;
        }
      } else {
        acc += d[idx] * (time[idx] - '0');
        dfs(idx + 1, acc);
      }
    };
    dfs(0, 0);
    return ans;
  }
};
