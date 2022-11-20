impl Solution {
  pub fn champagne_tower(poured: i32, query_row: i32, query_glass: i32) -> f64 {
      let mut f = vec![vec![0 as f64;query_row as usize + 1];query_row as usize + 1];
      f[0][0] = poured as f64;
      for i in 0..query_row as usize{
          for j in 0..=i {
              if f[i][j] > 1.0 {
                  let x = (f[i][j] - 1f64) / 2f64;
                  f[i + 1][j] += x;
                  f[i + 1][j + 1] += x;
              }
          }
      }
      f[query_row as usize][query_glass as usize].min(1f64)
  }
}