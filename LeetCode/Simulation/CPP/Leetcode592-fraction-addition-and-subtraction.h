class Solution {
 public:
  using LL = long long;
  // LL gcd(LL a,LL b) {
  //     return b ? gcd(b,a % b): a;
  // }
  string fractionAddition(string expression) {
    LL up = 0, down = 1;
    int n = expression.size();
    int i = 0;
    while (i < n) {
      int sign = 1;
      if (expression[i] == '-' || expression[i] == '+') {
        if (expression[i] == '-') sign = -1;
        i++;
      }
      LL up1 = 0, down1 = 0;
      while (i < n && isdigit(expression[i])) {
        up1 = up1 * 10 + expression[i] - '0';
        i++;
      }
      up1 = sign * up1;
      i++;

      while (i < n && isdigit(expression[i])) {
        down1 = down1 * 10 + expression[i] - '0';
        i++;
      }
      up = up1 * down + up * down1;
      down *= down1;
    }
    if (up == 0) return "0/1";
    cout << up << ' ' << down << endl;
    LL g = gcd(abs(up), down);
    cout << g << endl;
    return to_string(up / g) + "/" + to_string(down / g);
  }
};