#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
      int res = 0, truc = 0, n = arr.size();
      for(int i = 0;i < n;i++) {
        truc = max(arr[i],truc);
        res += (truc == i);
      }
      return res;
    }
};
