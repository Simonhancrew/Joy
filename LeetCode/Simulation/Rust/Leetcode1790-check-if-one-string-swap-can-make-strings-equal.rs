impl Solution {
  pub fn are_almost_equal(s1: String, s2: String) -> bool {
    if s1 == s2 {
      return true;
    }
    let s1 = s1.as_bytes();
    let s2 = s2.as_bytes();
    let (n, mut rec) = (s1.len(), Vec::new());
    for i in 0..n {
      if s1[i] != s2[i] {
        rec.push(i);
        if rec.len() > 2 {
          return false;
        }
      }
    }
    if rec.len() == 1 {
      return false;
    }
    s1[rec[0]] == s2[rec[1]] && s1[rec[1]] == s2[rec[0]]
  }
}
