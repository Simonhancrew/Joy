use std::collections::HashSet;
impl Solution {
  pub fn clear_stars(s: String) -> String {
    let mut cnt: Vec<Vec<usize>> = vec![vec![]; 26];
    let mut st = HashSet::new();
    let mut s = s.as_bytes();
    for i in 0..s.len() {
      if s[i] == b'*' {
        for j in 0..26 {
          if let Some(idx) = cnt[j].pop() {
            st.insert(idx);
            break;
          }
        }
      } else {
        let c = (s[i] - b'a') as usize;
        cnt[c].push(i);
      }
    }
    let mut ans = String::new();
    for i in 0..s.len() {
      if s[i] != b'*' && !st.contains(&i) {
        ans.push(s[i] as char);
      }
    }
    ans
  }
}
