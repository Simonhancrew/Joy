impl Solution {
  pub fn num_tilings(n: i32) -> i32 {
      let w = vec![[1, 1, 1, 1], [0, 0, 1, 1], [0, 1, 0, 1], [1, 0, 0, 0]];
      let p:i32 = 1e9 as i32 + 7;
      let n = n as usize;
      let mut f = vec![vec![0;4];n + 1];
      f[0][0] = 1;
      for i in 0..n {
          for j in 0..4 {
              for k in 0..4 {
                  f[i + 1][k] = (f[i + 1][k] + f[i][j] * w[j][k]) % p;
              }
          }
      }
      f[n][0]
  }
}