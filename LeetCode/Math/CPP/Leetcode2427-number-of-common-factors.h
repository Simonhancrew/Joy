class Solution {
 public:
  int commonFactors(int a, int b) {
    std::function<int(int, int)> gcd = [&](int a, int b) {
      return b ? gcd(b, a % b) : a;
    };
    int n = gcd(a, b), ans = 0;
    cout << n << endl;
    for (int i = 1; i <= n / i; i++) {
      if (n % i == 0)
        ans++;
      else
        continue;
      if (n / i != i) ans++;
    }
    return ans;
  }
};
