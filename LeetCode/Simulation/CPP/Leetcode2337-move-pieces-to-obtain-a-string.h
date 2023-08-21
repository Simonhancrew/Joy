#include <string>

using namespace std;

class Solution {
 public:
  bool canChange(string start, string target) {
    int n = start.size();
    int i = 0, j = 0;
    while (i < n && j < n) {
      while (i < n && start[i] == '_') {
        i++;
      }
      while (j < n && target[j] == '_') {
        j++;
      }
      if (i < n && j < n) {
        if (start[i] != target[j]) {
          return false;
        }
        auto c = start[i];
        if (c == 'L' && i < j) {
          return false;
        }
        if (c == 'R' && i > j) {
          return false;
        }
        i++, j++;
      }
    }
    while (i < n) {
      if (start[i++] != '_') {
        return false;
      }
    }
    while (j < n) {
      if (target[j++] != '_') {
        return false;
      }
    }
    return true;
  }
};
