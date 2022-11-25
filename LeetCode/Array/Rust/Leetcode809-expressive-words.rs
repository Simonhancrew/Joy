impl Solution {
  pub fn expressive_words(s: String, words: Vec<String>) -> i32 {
      let (n, mut i, s) = (s.len(), 0, s.as_bytes());
      let mut rec = vec![];
      while i < n {
          let mut j = i + 1;
          while j < n && s[j] == s[i] {
              j += 1;
          }
          rec.push(vec![s[i] as usize, j - i]);
          i = j;
      }
      let check = |w:&str| -> bool {
          let (w, n) = (w.as_bytes(), w.len());
          let (mut i,mut k) = (0, 0);
          while i < n {
              if k == rec.len() {
                  return false;
              }
              if w[i] as usize != rec[k][0] {
                  return false;
              }
              let mut j = i + 1;
              while j < n && w[j] == w[i] {
                  j += 1;
              }
              let (difs, difw) = (rec[k][1], j - i);
              if difs < difw {
                  return false;
              }
              if difs < 3 && difw != difs {
                  return false;
              }
              k += 1;
              i = j;
          }
          k == rec.len()
      };
      let mut ans = 0;
      for w in &words {
          if check(w) {
              ans += 1;
          }
      }
      ans
  }
}