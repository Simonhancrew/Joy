impl Solution {
  pub fn distinct_subseq_ii(s: String) -> i32 {
    let (n, MOD) = (s.len(), 1e9 as i32 + 7);
    let mut f = vec![0; 26];
    let s = s.as_bytes();
    f[(s[0] - b'a') as usize] = 1;
    for i in 1..n {
      let mut rec = 0;
      for x in &f {
        rec = (rec + x) % MOD;
      }
      f[(s[i] - b'a') as usize] = rec + 1;
    }
    let mut res = 0;
    for x in &f {
      res = (res + x) % MOD;
    }
    res
  }
}
