impl Solution {
  pub fn min_operations(s: String) -> i32 {
    let (mut ans, n) = (0, s.len());
    let s = s.as_bytes();
    for i in 0..n {
      if s[i] != b'0' + (i % 2) as u8 {
        ans += 1;
      }
    }
    ans.min(n as i32 - ans)
  }
}
