impl Solution {
  pub fn new21_game(n: i32, k: i32, max_pts: i32) -> f64 {
    let mut f = vec![0f64; n as usize + 1];
    let mut s = 0f64;
    for i in (0..=n as usize).rev() {
      f[i] = if i >= k as usize { 1f64 } else { s / max_pts as f64 };
      s += f[i];
      if i as i32 + max_pts <= n {
        s -= f[i + max_pts as usize];
      }
    }
    f[0]
  }
}
