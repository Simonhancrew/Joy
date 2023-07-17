#include <string>

using namespace std;

class Solution {
 public:
  string addStrings(string num1, string num2) {
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    string ans;
    int acc = 0, i;
    for (i = 0; i < num1.size() && i < num2.size(); ++i) {
      int cur = num1[i] - '0' + num2[i] - '0' + acc;
      ans.push_back(cur % 10 + '0');
      acc = cur / 10;
    }
    while (i < num1.size()) {
      int cur = num1[i] - '0' + acc;
      ans.push_back(cur % 10 + '0');
      acc = cur / 10;
      i++;
    }
    while (i < num2.size()) {
      int cur = num2[i] - '0' + acc;
      ans.push_back(cur % 10 + '0');
      acc = cur / 10;
      ++i;
    }
    if (acc) {
      ans.push_back(acc % 10 + '0');
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
