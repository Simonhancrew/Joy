class MovingAverage {
 public:
  /** Initialize your data structure here. */
  int size_;
  static const int N = 1e4 + 10;
  int arr[N];
  int st, ed, sum;
  MovingAverage(int size) {
    st = 0, ed = 0, sum = 0;
    size_ = size;
  }

  double next(int val) {
    arr[ed++] = val, sum += val;
    if (ed - st > size_) sum -= arr[st++];
    return static_cast<double>(sum) / (ed - st);
  }
};
