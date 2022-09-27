impl Solution {
  pub fn check_permutation(s1: String, s2: String) -> bool {
      if s1.len() != s2.len() {
          return false;
      }
      let mut rec = vec![0;26];
      for s in s1.as_bytes() {
          rec[(s - b'a') as usize] += 1;
      }
      for s in s2.as_bytes() {
          rec[(s - b'a') as usize] -= 1;
          if rec[(s - b'a') as usize] < 0 {
              return false;
          }
      }
      true
  }
}