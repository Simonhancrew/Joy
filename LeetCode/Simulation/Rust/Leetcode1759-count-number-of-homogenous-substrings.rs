impl Solution {
  pub fn count_homogenous(s: String) -> i32 {
    let (mut res, n) = (0, s.len());
    let (mut i, MOD) = (0, 1e9 as i32 + 7);
    while i < n {
      let mut j = i;
      while j < n && s.as_bytes()[j] == s.as_bytes()[i] {
        j += 1;
      }
      let d = j - i;
      res += ((d as i64 * (d as i64 + 1i64) / 2i64) % MOD as i64) as i32;
      i = j;
    }
    res
  }
}
