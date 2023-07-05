#include <algorithm>

using namespace std;

class Solution {
 public:
  int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
    return min(numOnes, k) - max(k - numOnes - numZeros, 0);
  }
};
