use std::collections::HashSet;
impl Solution {
  pub fn num_unique_emails(emails: Vec<String>) -> i32 {
    let mut st = HashSet::new();
    for s in &emails {
      let mut t = String::new();
      for mut i in 0..s.len() {
        if &s[i..i + 1] == "." {
          continue;
        }
        if &s[i..i + 1] == "@" {
          t += &s[i..s.len()];
          break;
        }
        if &s[i..i + 1] == "+" {
          while &s[i..i + 1] != "@" {
            i += 1;
          }
          t += &s[i..s.len()];
          break;
        }
        t += &s[i..i + 1];
      }
      st.insert(t);
    }
    st.len() as i32
  }
}
