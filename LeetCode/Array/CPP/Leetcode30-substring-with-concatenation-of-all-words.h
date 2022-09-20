/*
    两个哈希表记录，rec记录word中每个字符包含个数
    从后往前滑窗，tmp记录出现的word的个数，比照最后两个哈希表是否一致
    实际比较中，判断哈希表是否一致有个技巧就是开一个有效增减计数。
*/
class Solution {
 public:
  vector<int> findSubstring(string s, vector<string> &words) {
    int n = s.size(), m = words.size(), w = words[0].size();
    vector<int> res;
    if (!words.size()) return res;
    unordered_map<string, int> rec;
    for (auto &ss : words) rec[ss]++;

    for (int i = 0; i < w; i++) {
      unordered_map<string, int> tmp;
      int cnt = 0;
      for (int j = i; j + w <= n; j += w) {
        if (j >= i + m * w) {
          string t = s.substr(j - m * w, w);
          tmp[t]--;
          // 有效的字符串减少了，总体的cnt需要-1
          if (tmp[t] < rec[t]) cnt--;
        }
        string t = s.substr(j, w);
        tmp[t]++;
        // 合法的words里的子串
        if (tmp[t] <= rec[t]) cnt++;
        // 总体的数量满足words.size()
        if (cnt == m) res.push_back(j - (m - 1) * w);
      }
    }
    return res;
  }
};
