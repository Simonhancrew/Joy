impl Solution {
  pub fn min_side_jumps(obstacles: Vec<i32>) -> i32 {
      let n = obstacles.len();
      let mut f = vec![1, 0, 1];
      for i in 1..n {
          let mut mn = i32::MAX;
          for j in 0..3 {
              if obstacles[i] == j as i32 + 1 {
                  f[j] = i32::MAX;
                  continue;
              }
              mn = mn.min(f[j]);
          }
          for j in 0..3 {
              if obstacles[i] == j as i32 + 1 {
                  continue;
              }
              f[j] = f[j].min(mn + 1);
          }
      }
      f[0].min(f[1]).min(f[2])
  }
}