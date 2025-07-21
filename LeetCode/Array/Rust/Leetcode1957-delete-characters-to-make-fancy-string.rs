impl Solution {
  pub fn make_fancy_string(s: String) -> String {
    if s.len() < 3 {
      return s;
    }
    let (mut ans, mut cnt) = (vec![], 0);
    for (i, &c) in s.as_bytes().into_iter().enumerate() {
      cnt += 1;
      if cnt < 3 {
        ans.push(c);
      }
      if i < s.len() - 1 && s.as_bytes()[i] != s.as_bytes()[i + 1] {
        cnt = 0;
      }
    }
    unsafe { String::from_utf8_unchecked(ans) }
  }
}
