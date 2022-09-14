class Bank {
 public:
  typedef long long LL;
  vector<LL> rec;
  int n;
  Bank(vector<long long> &balance) {
    n = balance.size();
    rec = balance;
  }

  bool transfer(int account1, int account2, long long money) {
    if (account1 > n || account1 < 1 || account2 > n || account2 < 1)
      return false;
    if (rec[account1 - 1] < money) return false;
    rec[account1 - 1] -= money;
    rec[account2 - 1] += money;
    return true;
  }

  bool deposit(int account, long long money) {
    if (account < 1 || account > n) return false;
    rec[account - 1] += money;
    return true;
  }

  bool withdraw(int account, long long money) {
    if (account < 1 || account > n) return false;
    if (rec[account - 1] < money) return false;
    rec[account - 1] -= money;
    return true;
  }
};