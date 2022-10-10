impl Solution {
  pub fn min_swap(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
      let n = nums1.len();
      let mut f = vec![vec![1e9 as i32;2];n];
      f[0][0] = 0;
      f[0][1] = 1;
      for i in 1..n {
          if nums1[i] > nums1[i-1] && nums2[i] > nums2[i-1] {
              f[i][0] = f[i][0].min(f[i-1][0]);
              f[i][1] = f[i][1].min(f[i-1][1]+1);
          }
          if nums1[i] > nums2[i-1] && nums2[i] > nums1[i-1] {
              f[i][0] = f[i][0].min(f[i-1][1]);
              f[i][1] = f[i][1].min(f[i-1][0]+1);
          }
      }
      f[n - 1][0].min(f[n - 1][1])
  }
}