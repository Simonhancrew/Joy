#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<string> splitWordsBySeparator(vector<string> &words, char separator) {
    vector<string> res;
    for (const auto &s : words) {
      stringstream ss(s);
      string sub;
      while (getline(ss, sub, separator)) {
        if (!sub.empty()) {
          res.push_back(std::move(sub));
        }
      }
    }
    return res;
  }
};
