class Solution {
 public:
  bool checkOnesSegment(string s) {
    int n = s.size(), cnt = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') {
        if (flag)
          continue;
        else {
          cnt++;
          if (cnt > 1)
            return false;
          flag = true;
        }
      } else {
        flag = false;
      }
    }
    return true;
  }
};