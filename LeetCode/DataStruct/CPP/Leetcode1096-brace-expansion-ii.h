// 表达式求值， 维护一个循环不变量就行了
// A + B (* or +) (C), 初始的时候保证work， A应该是空集， Ｂ＊ C 要维持原状， B
// 应该加入""
class Solution {
 public:
  using SS = set<string>;
  vector<string> braceExpansionII(string expression) {
    auto add = [](SS& a, SS& b) {
      SS c(a.begin(), a.end());
      for (auto& x : b) {
        if (x.size()) {
          c.insert(x);
        }
      }
      return c;
    };
    auto mul = [](SS& a, SS& b) {
      SS c;
      for (const auto& x : a) {
        for (const auto& y : b) {
          c.insert(x + y);
        }
      }
      return c;
    };
    int k = 0;
    std::function<SS()> dfs = [&]() -> SS {
      SS a, b;
      b.insert("");
      while (k < expression.size() && expression[k] != '}') {
        bool is_add = true;
        if (!k || expression[k - 1] != ',') is_add = false;
        SS c;
        if (expression[k] == ',') {
          k++;
          continue;
        } else if (expression[k] == '{') {
          k++;  // {
          c = dfs();
          k++;  // }
        } else {
          string s;
          while (k < expression.size() && expression[k] >= 'a' && expression[k] <= 'z') {
            s += expression[k++];
          }
          c.insert(s);
        }
        if (is_add) {
          a = add(a, b);
          b = c;
        } else {
          b = mul(b, c);
        }
      }
      return add(a, b);
    };
    auto st = dfs();
    return {st.begin(), st.end()};
  }
};
