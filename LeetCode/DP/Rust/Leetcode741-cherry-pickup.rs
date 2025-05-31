impl Solution {
  pub fn cherry_pickup(grid: Vec<Vec<i32>>) -> i32 {
    let n = grid.len();
    let mut f = vec![vec![vec![-100000; 2 * n + 1]; n + 1]; n + 1];
    f[1][1][2] = grid[0][0];
    for k in 3..=(2 * n) {
      let (l, r) = (1.max(k as i32 - n as i32), (n as i32).min(k as i32 - 1)); // 越界的问题
      let (l, r) = (l as usize, r as usize);
      for i in l..=r {
        for j in l..=r {
          if grid[i - 1][k - i - 1] == -1 || grid[j - 1][k - j - 1] == -1 {
            continue;
          }
          let mut t = grid[i - 1][k - i - 1];
          if i != j {
            t += grid[j - 1][k - j - 1];
          }
          for a in (i - 1)..=i {
            for b in (j - 1)..=j {
              f[i][j][k] = f[i][j][k].max(f[a][b][k - 1] + t);
            }
          }
        }
      }
    }
    0.max(f[n][n][2 * n])
  }
}
