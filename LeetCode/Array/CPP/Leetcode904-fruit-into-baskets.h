#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
      unordered_map<int, int> mp;
      int n = fruits.size(),res = 0;
      for(int i = 0, j = 0, s = 0;i < n;i++) {
        if(++mp[fruits[i]] == 1) s++;
        while(s > 2) {
          if(--mp[fruits[j]] == 0) --s;
          ++j;
        }
        res = max(res, i - j + 1);
      }
      return res;
    }
};
