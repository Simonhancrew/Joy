#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    double trimMean(vector<int>& arr) {
      sort(arr.begin(),arr.end());
      int n = arr.size();
      int acc = std::accumulate(arr.begin() + n / 20,arr.begin() + (19 * n / 20),0);
      return acc / (0.9 * n);
    }
};
