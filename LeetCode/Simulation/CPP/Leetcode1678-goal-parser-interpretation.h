class Solution {
 public:
  string interpret(string s) {
    string res;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == 'G')
        res += 'G';
      else {
        int j = i;
        while (s[j] != ')') j++;
        if (j - i <= 1)
          res += 'o';
        else
          res += "al";
        i = j;
      }
    }
    return res;
  }
};