impl Solution {
  pub fn largest_sum_of_averages(nums: Vec<i32>, k: i32) -> f64 {
    let n = nums.len();
    let (mut f, mut s) = (vec![vec![-10000f64; k as usize + 1]; n + 1], vec![0f64; n + 1]);
    f[0][0] = 0f64;
    for i in 1..=n {
      s[i] = s[i - 1] + nums[i - 1] as f64;
    }
    for i in 1..=n {
      for j in 1..=k as usize {
        for q in 0..i {
          f[i][j] = f[i][j].max(f[q][j - 1] + (s[i] - s[q]) / (i as f64 - q as f64));
        }
      }
    }
    f[n][k as usize]
  }
}
