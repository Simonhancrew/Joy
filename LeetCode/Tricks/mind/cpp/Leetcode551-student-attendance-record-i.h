#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
  bool checkRecord(string s) {
    return ranges::count(s, 'A') < 2 && s.find("LLL") == string::npos;
  }
};
