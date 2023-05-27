class Solution {
 public:
  vector<double> sampleStats(vector<int>& count) {
    vector<double> res{INT_MAX, INT_MIN, 0, 0, 0};
    int n = count.size(), mx_freq = 0, cnt = 0;
    int tot = accumulate(count.begin(), count.end(), 0);
    // 中位数，奇数和偶数放到一起处理，奇数同一个+两次
    int lhs = (tot + 1) / 2, rhs = (tot + 2) / 2;
    double acc = 0;
    for (int i = 0; i < n; i++) {
      if (count[i] == 0) continue;
      res[0] = min(res[0], (double)i);
      res[1] = max(res[1], (double)i);
      acc += (double)count[i] * i;
      if (count[i] > mx_freq) {
        mx_freq = count[i];
        res[4] = i;
      }
      if (cnt < lhs && cnt + count[i] >= lhs) {
        res[3] += i;
      }
      if (cnt < rhs && cnt + count[i] >= rhs) {
        res[3] += i;
      }
      cnt += count[i];
    }
    res[2] = acc / tot;
    res[3] /= 2;
    return res;
  }
};