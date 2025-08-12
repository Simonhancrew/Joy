impl Solution {
  pub fn number_of_ways(n: i32, x: i32) -> i32 {
    let qpow = |mut a: i32, mut b: i32| -> i32 {
      let mut res = 1;
      while b != 0 {
        if b & 1 == 1 {
          res *= a;
        }
        a *= a;
        b >>= 1;
      }
      res
    };
    let (mut f, mut i, MOD) = (vec![0i64; n as usize + 1], 1, 1e9 as i64 + 7);
    f[0] = 1;
    while qpow(i, x) <= n {
      let cur = qpow(i, x);
      for j in (cur..=n).rev() {
        f[j as usize] += f[(j - cur) as usize];
      }
      i += 1;
    }
    (f[n as usize] % MOD) as _
  }
}
