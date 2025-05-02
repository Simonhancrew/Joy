impl Solution {
  pub fn push_dominoes(dominoes: String) -> String {
      let mut s = format!("L{}R", dominoes).into_bytes();
      fn fill(s: &mut [u8], ch: u8) {
          for i in s {
              *i = ch;
          }
      }
      let mut pre = 0;
      for i in 1..s.len() {
          if s[i] == b'.' {
              continue;
          }
          let ch: u8 = s[i];
          if s[i] == s[pre] {
              fill(&mut s[pre + 1..i], ch);
          } else if s[i] == b'L' {
              fill(&mut s[pre + 1..=(pre + i - 1) / 2], b'R');
              fill(&mut s[(pre + i) / 2 + 1..i], b'L');
          }
          pre = i;
      }
      unsafe {String::from_utf8_unchecked(s[1..s.len() - 1].to_owned()) }
  }
}