use std::collections::HashSet;
impl Solution {
  pub fn halves_are_alike(s: String) -> bool {
    let (n, mut cnt) = (s.len() / 2, 0);
    let st = HashSet::from([b'a', b'e', b'i', b'o', b'u', b'A', b'E', b'I', b'O', b'U']);
    for i in 0..n {
      if st.contains(&s.as_bytes()[i]) {
        cnt += 1;
      }
    }
    for i in n..n * 2 {
      if st.contains(&s.as_bytes()[i]) {
        cnt -= 1;
      }
      if cnt < 0 {
        return false;
      }
    }
    cnt == 0
  }
}
