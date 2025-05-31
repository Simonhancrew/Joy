use std::collections::HashMap;
impl Solution {
  pub fn find_substring_in_wrapround_string(p: String) -> i32 {
    let mut mp = HashMap::new();
    let mut i = 0;
    let p = p.as_bytes();
    while i < p.len() {
      let mut j = i + 1;
      while j < p.len() && (p[j] - p[j - 1] == 1 || (p[j] == b'a' && p[j - 1] == b'z')) {
        j += 1;
      }
      while i < j {
        let cnt = mp.entry(&p[i..i + 1]).or_insert(j - i);
        *cnt = (*cnt).max(j - i);
        i += 1;
      }
    }
    let mut res = 0;
    for (_k, v) in mp {
      res += v;
    }
    res as i32
  }
}
