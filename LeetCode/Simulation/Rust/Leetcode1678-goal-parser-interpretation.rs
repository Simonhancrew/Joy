impl Solution {
  pub fn interpret(s: String) -> String {
    let mut res = String::new();
    let mut i = 0;
    while i < s.len() {
      if s.as_bytes()[i] == b'G' {
        res.push('G');
      } else {
        let mut j = i;
        while s.as_bytes()[j] != b')' {
          j += 1;
        }
        if j - i <= 1 {
          res.push('o');
        } else {
          res.push_str("al");
        }
        i = j;
      }
      i += 1;
    }
    res
  }
}
