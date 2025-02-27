class TextEditor {
 public:
  std::string lhs, rhs;
  TextEditor() {
  }

  void addText(string text) {
    lhs.append(text);
  }

  int deleteText(int k) {
    int res = min(k, (int)lhs.size());
    lhs.resize(lhs.size() - res);
    return res;
  }

  string text() {
    return lhs.substr(max((int)lhs.size() - 10, 0));
  }
  string cursorLeft(int k) {
    while (k && lhs.size()) {
      auto c = lhs.back();
      lhs.pop_back();
      rhs.push_back(c);
      k--;
    }
    return text();
  }

  string cursorRight(int k) {
    while (k && rhs.size()) {
      auto c = rhs.back();
      rhs.pop_back();
      lhs.push_back(c);
      k--;
    }
    return text();
  }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
