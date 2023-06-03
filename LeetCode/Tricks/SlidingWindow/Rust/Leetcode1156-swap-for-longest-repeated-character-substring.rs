impl Solution {
  pub fn max_rep_opt1(text: String) -> i32 {
      let n = text.len();
      let mut f = vec![vec![];26];
      let text = text.as_bytes();
      for i in 0..n {
          f[(text[i] - b'a') as usize].push(i);
      }
      let mut res = 0;
      for p in &f {
          let mut j = 0;
          for i in 0..p.len() {
              while p[i] - p[j] > i - j + 1 {
                  j += 1;
              }
              if i + 1 < p.len() || j > 0 {
                  res = res.max(p[i] - p[j] + 1);
              }
          }
          j = 0;
          for i in 0..p.len() {
              while p[i] - p[j] > i - j {
                  j += 1;
              }
              let mut cur = p[i] - p[j] + 1;
              if i + 1 < p.len() || j > 0 {
                  cur += 1;
              }
              res = res.max(cur);
          }
      }
      res as i32
  }
}
