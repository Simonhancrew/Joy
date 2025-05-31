impl Solution {
  pub fn soup_servings(mut n: i32) -> f64 {
    n = (n + 24) / 25;
    if n >= 200 {
      return 1f64;
    }
    let gen = |x: i32| -> usize { x.max(0) as usize };
    let mut f = vec![vec![0f64; n as usize + 1]; n as usize + 1];
    for i in 0..=n as usize {
      for j in 0..=n as usize {
        if i == 0 && j == 0 {
          f[i][j] = 0.5;
        } else if i != 0 && j == 0 {
          f[i][j] = 0f64;
        } else if i == 0 && j != 0 {
          f[i][j] = 1f64;
        } else {
          let (i, j) = (i as i32, j as i32);
          f[i as usize][j as usize] = (f[gen(i - 4)][j as usize]
            + f[gen(i - 3)][gen(j - 1)]
            + f[gen(i - 2)][gen(j - 2)]
            + f[gen(i - 1)][gen(j - 3)])
            / 4f64;
        }
      }
    }
    f[n as usize][n as usize]
  }
}
