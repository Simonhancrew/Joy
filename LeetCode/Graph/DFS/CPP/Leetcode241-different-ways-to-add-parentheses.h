class Solution {
 public:
  vector<int> diffWaysToCompute(string expression) {
    vector<int> res;
    int n = expression.size();
    for (int i = 0; i < n; i++) {
      if (!isdigit(expression[i])) {
        auto left = diffWaysToCompute(expression.substr(0, i));
        auto right = diffWaysToCompute(expression.substr(i + 1));
        for (auto lhs : left) {
          for (auto rhs : right) {
            if (expression[i] == '+') {
              res.push_back(lhs + rhs);
            } else if (expression[i] == '-') {
              res.push_back(lhs - rhs);
            } else if (expression[i] == '*') {
              res.push_back(lhs * rhs);
            }
          }
        }
      }
    }
    if (res.empty()) {
      res.push_back(stoi(expression));
    }
    return res;
  }
};