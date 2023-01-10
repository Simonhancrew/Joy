// 欧拉回路， n位k进，总共有k ^ n的可能串
// 随意构造前n - 1位，随后在最后一位选择任意数组成n位新串，与之前的不重复
// 然后再从后n - 1位重复上述操作，不难知道这个操作筛选到不重复的
// 最终结果需要k ^ n次操作，
// 总共的串就是str(n - 1的起始串) + str(k ^ n次操作的串拼接)
// 因为是欧拉回路，所以随便选一个起始都可以
class Solution {
 public:
  string crackSafe(int n, int k) {
    string start(n - 1, '0'), ans;
    unordered_set<string> st;
    function<void(string)> dfs = [&](string s) {
      for (int i = 0; i < k; i++) {
        auto t = s + to_string(i);
        if (st.count(t)) continue;
        st.insert(t);
        dfs(t.substr(1));
        ans += to_string(i);
      }
    };
    dfs(start);
    return ans + start;
  }
};
