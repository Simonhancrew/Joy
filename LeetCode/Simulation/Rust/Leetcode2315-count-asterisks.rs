impl Solution {
  pub fn count_asterisks(s: String) -> i32 {
      let (mut flag, mut ans) = (true, 0);
      for &u in s.as_bytes() {
          if u == b'|' {
              flag = !flag;
          } else if u == b'*' && flag {
              ans += 1;
          }
      }
      ans
  }
}