#include <algorithm>
#include <vector>

using namespace std;

class Solution {
 public:
  int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    int n = dist.size();
    vector<int> rec(n);
    for (int i = 0; i < n; i++) {
      rec[i] = ((dist[i] + speed[i] - 1) / speed[i]);
    }
    sort(rec.begin(), rec.end());
    for (int i = 0; i < n; i++) {
      if (rec[i] <= i) {
        return i;
      }
    }
    return n;
  }
};
