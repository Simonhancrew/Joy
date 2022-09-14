class Solution {
 public:
  string reversePrefix(string word, char ch) {
    auto pos = find(word.begin(), word.end(), ch) - word.begin();
    if (pos < word.size()) {
      reverse(word.begin(), word.begin() + pos + 1);
    }
    return word;
  }
};
