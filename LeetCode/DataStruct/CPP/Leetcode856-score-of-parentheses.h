#include <string>
#include <stack>

using namespace std;

class Solution {
public:
  int scoreOfParentheses(string s) {
    stack<int> stk;
    stk.push(0);
    int n = s.size();
    for(int i = 0;i < n;i++) {
      if(s[i] == '(') stk.push(0);
      else {
          int t = stk.top();
          stk.pop();
          if(t == 0) {
            stk.top() += 1;
          }else {
            stk.top() += 2 * t;
          }
        }
    }
    return stk.top();
  }
};
