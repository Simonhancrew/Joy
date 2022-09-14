/*
    下标有序，一个贪心的思路是遍历中记录最后找到的word下标。然后相减
*/
class Solution {
 public:
  int findClosest(vector<string> &words, string word1, string word2) {
    int l = -1, r = -1, n = words.size();
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
      if (words[i] == word1) l = i;
      if (words[i] == word2) r = i;
      if (l >= 0 && r >= 0) ans = min(ans, abs(r - l));
    }
    return ans;
  }
};

#ifdef FILEIO
// 如果读写文件的话，更好的做法是构造函数里传words，然后构建一个表
// 因为两表的id都是递增的，因此确定一个pair大小序(比如保证l[index1] <
// r[index2]), 做一个O(m + n)的遍历就可以
class Solution {
 public:
  int findClosest(vector<string> &words, string word1, string word2) {
    unordered_map<string, vector<int>> mp;
    for (int i = 0; i < words.size(); i++) {
      mp[words[i]].push_back(i);
    }
    vector<int> &l = mp[word1], &r = mp[word2];
    int ans = INT_MAX, i = 0, j = 0;
    while (i < l.size() && j < r.size()) {
      ans = min(ans, abs(l[i] - r[j]));
      if (l[i] < r[j])
        i++;
      else
        j++;
    }
    return ans;
  }
};
#endif