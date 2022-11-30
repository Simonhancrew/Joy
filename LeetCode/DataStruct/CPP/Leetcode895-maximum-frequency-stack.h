class FreqStack {
 public:
  FreqStack() {}

  void push(int val) {
    freq[val]++;
    rec[freq[val]].push_back(val);
    mx = max(freq[val], mx);
  }

  int pop() {
    int res = rec[mx].back();
    rec[mx].pop_back();
    freq[res]--;
    if (rec[mx].empty()) mx--;
    return res;
  }

  unordered_map<int, int> freq;
  unordered_map<int, vector<int>> rec;
  int mx = 0;
};
