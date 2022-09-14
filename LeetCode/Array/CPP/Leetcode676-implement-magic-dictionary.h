class MagicDictionary {
 public:
  MagicDictionary() {}

  void buildDict(vector<string> dictionary) { rec = std::move(dictionary); }

  bool search(string searchWord) {
    for (auto const &pattern : rec) {
      if (pattern.size() != searchWord.size()) continue;
      int diff = 0;
      for (int i = 0; i < pattern.size(); i++) {
        if (pattern[i] != searchWord[i]) diff++;
        if (diff > 1) break;
      }
      if (diff == 1) return true;
    }

    return false;
  }

 private:
  vector<string> rec;
};
