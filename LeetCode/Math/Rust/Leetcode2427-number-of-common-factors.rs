impl Solution {
  fn gcd(a: i32, b: i32) -> i32 {
    if b == 0 {
      a
    } else {
      Self::gcd(b, a % b)
    }
  }

  pub fn common_factors(a: i32, b: i32) -> i32 {
    let n = Self::gcd(a, b);
    let mut i = 1;
    let mut ans = 0;
    while i <= n / i {
      if n % i != 0 {
        i += 1;
        continue;
      }
      ans += 1;
      if n / i != i {
        ans += 1;
      }
      i += 1;
    }
    ans
  }
}
