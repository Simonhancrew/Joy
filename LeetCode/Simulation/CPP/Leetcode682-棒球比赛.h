class Solution {
 public:
  int calPoints(vector<string>& ops) {
    int ans = 0;
    vector<int> rec;
    for (auto& op : ops) {
      int n = rec.size();
      switch (op[0]) {
        case '+':
          ans += rec[n - 1] + rec[n - 2];
          rec.push_back(rec[n - 1] + rec[n - 2]);
          break;
        case 'C':
          ans -= rec[n - 1];
          rec.pop_back();
          break;
        case 'D':
          ans += rec[n - 1] * 2;
          rec.push_back(rec[n - 1] * 2);
          break;
        default:
          ans += stoi(op);
          rec.push_back(stoi(op));
          break;
      }
    }
    return ans;
  }
};