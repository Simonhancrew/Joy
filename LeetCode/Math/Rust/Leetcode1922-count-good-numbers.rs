impl Solution {
  pub fn count_good_numbers(n: i64) -> i32 {
    let MOD = 1e9 as i64 + 7;
    let qpow = |mut a: i64, mut b: i64| -> i64 {
      let mut res = 1i64;
      while b != 0 {
        if b & 1 == 1 {
          res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
      }
      res
    };
    (qpow(5i64, (n + 1) / 2) * qpow(4i64, n / 2) % MOD) as _
  }
}
