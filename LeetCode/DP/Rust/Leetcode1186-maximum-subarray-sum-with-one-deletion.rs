impl Solution {
  pub fn maximum_sum(arr: Vec<i32>) -> i32 {
      let n = arr.len();
      let (mut f, mut g) = (vec![0;n],vec![0;n]);
      f[0] = arr[0];
      g[0] = -1e5 as i32;
      let mut ans = f[0];
      for i in 1..n {
          f[i] = arr[i].max(f[i - 1 ] + arr[i]);
          g[i] = f[i - 1].max(g[i - 1] + arr[i]);
          ans = ans.max(f[i]).max(g[i]);
      }
      ans
  }
}
