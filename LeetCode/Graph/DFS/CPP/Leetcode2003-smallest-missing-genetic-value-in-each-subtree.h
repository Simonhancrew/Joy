#include <functional>
#include <unordered_set>
#include <vector>

using namespace std;

// 从nums = 1的节点开始dfs，找到最小的不在子树中的数，然后继续往父节点找
// 此时因为在一条路上，所以这个不在子树中的数往上的时候一定会一路递增
// 如果nums = 1的节点就是根节点，别的子树的值就都是1

class Solution {
 public:
  static vector<int> smallestMissingValueSubtree(const vector<int>& parents,
                                          vector<int>& nums) {
    int n = parents.size();
    vector<int> ans(n, 1);
    auto it = find(nums.begin(), nums.end(), 1);
    if (it == nums.end()) {
      return ans;
    }
    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
      g[parents[i]].push_back(i);
    }
    unordered_set<int> st;
    function<void(int)> dfs = [&dfs, &st, &g, &nums](int x) {
      st.insert(nums[x]);
      for (const auto ne : g[x]) {
        if (st.count(nums[ne])) continue;
        st.insert(nums[ne]);
        dfs(ne);
      }
    };
    int next = 2;
    auto idx = it - nums.begin();
    while (idx >= 0) {
      dfs(idx);
      while (st.count(next)) {
        next++;
      }
      ans[idx] = next;
      idx = parents[idx];
    }
    return ans;
  }
};
