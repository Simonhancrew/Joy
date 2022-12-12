impl Solution {
  pub fn check_if_pangram(sentence: String) -> bool {
      if sentence.len() < 26 {
        return false;
      }
      let mut rec = vec![false;26];
      for x in sentence.as_bytes() {
          rec[(x - b'a') as usize] = true;
      }
      for i in 0..26 {
          if !rec[i] {
              return false;
          } 
      }
      true
  }
}