class BrowserHistory {
 public:
  vector<string> arr;
  int cur{};
  BrowserHistory(string homepage) {
    arr.emplace_back(std::move(homepage));
  }

  void visit(string url) {
    cur++;
    arr.resize(cur);
    arr.push_back(std::move(url));
  }

  string back(int steps) {
    cur = max(0, cur - steps);
    return arr[cur];
  }

  string forward(int steps) {
    int mx = arr.size() - 1;
    cur    = min(mx, cur + steps);
    return arr[cur];
  }
};
