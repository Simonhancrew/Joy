// begin -> last
impl Solution {
  pub fn get_smallest_string(n: i32, mut k: i32) -> String {
      let mut ans = vec![];
      for i in 1..=n {
          let cur = 1.max(k - (n - i) * 26);
          ans.push(b'a' + (cur - 1) as u8);
          k -= cur;
      }
      if let Ok(s) = String::from_utf8(ans) {
          return s;
      }
      panic!()
  }
}