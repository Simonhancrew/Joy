#include <functional>
#include <string>

using namespace std;

// ,分割，所以递归下去，遇到#表是当前搜索方向结束，返回true，然后继续可以搜的下一个方向
// 模拟dfs前序遍历，如果最后idx到达字符串末尾，说明是合法的

class Solution {
public:
  bool isValidSerialization(string preorder) {
    preorder += ',';
    int idx{};
    std::function<bool()> dfs = [&]() {
      if (idx == preorder.size()) {
        return false;
      }
      if (preorder[idx] == '#') {
        idx += 2;
        return true;
      }
      while (preorder[idx] != ',') {
        idx++;
      }
      idx++;
      return dfs() && dfs();
    };
    if (!dfs()) {
      return false;
    }
    return idx == preorder.size();
  }
};
