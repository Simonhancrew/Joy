impl Solution {
  pub fn max_height(mut cuboids: Vec<Vec<i32>>) -> i32 {
    for x in &mut cuboids {
      x.sort();
    }
    cuboids.sort_by(|a, b| a.cmp(b));
    cuboids.reverse();
    let n = cuboids.len();
    let (mut res, mut f) = (0, vec![0; n]);
    for i in 0..n {
      f[i] = cuboids[i][2];
      for j in 0..i {
        if cuboids[j][1] >= cuboids[i][1] && cuboids[j][2] >= cuboids[i][2] {
          f[i] = f[i].max(f[j] + cuboids[i][2]);
        }
      }
      res = res.max(f[i]);
    }
    res
  }
}
