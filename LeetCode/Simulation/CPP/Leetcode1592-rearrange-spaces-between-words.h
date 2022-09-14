class Solution {
 public:
  string reorderSpaces(string text) {
    vector<string> words;
    int n = text.size(), sp = 0;
    for (int i = 0; i < n; i++) {
      while (i < n && text[i] == ' ') {
        sp++;
        i++;
      }
      if (i == n) break;
      int j = i;
      while (j < n && text[j] != ' ') j++;
      auto t = text.substr(i, j - i);
      words.push_back(t);
      i = j - 1;
    }
    int wd = words.size();
    if (wd == 1) return words[0] + string(sp, ' ');
    int inter = sp / (wd - 1), extra = sp % (wd - 1);
    string ans;
    for (int i = 0; i < wd - 1; i++) {
      ans += words[i];
      ans += string(inter, ' ');
    }
    ans += words.back();
    if (extra) ans += string(extra, ' ');
    return ans;
  }
};