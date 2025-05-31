impl Solution {
  pub fn max_sum_after_partitioning(arr: Vec<i32>, k: i32) -> i32 {
    let n = arr.len();
    let mut f = vec![0; n + 1];
    for i in 0..=n {
      let (mut l, mut v) = (1, 0);
      while l <= k && l <= i as i32 {
        v = v.max(arr[i - l as usize]);
        f[i] = f[i].max(f[i - l as usize] + v * l);
        l += 1
      }
    }
    f[n]
  }
}
