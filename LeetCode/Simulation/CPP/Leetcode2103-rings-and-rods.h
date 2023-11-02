#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
 public:
  const unordered_map<char, int> mp{{'R', 1}, {'G', 2}, {'B', 4}};
  int countPoints(string rings) {
    int n = rings.size() / 2;
    vector<int> f(10);
    for (int i = 0; i < 2 * n; i += 2) {
      int cor = mp.at(rings[i]);
      int id = rings[i + 1] - '0';
      f[id] |= cor;
    }
    int ans = 0;
    for (int i = 0; i < 10; i++) {
      if (f[i] == 7) {
        ans++;
      }
    }
    return ans;
  }
};