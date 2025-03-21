impl Solution {
  pub fn maximum_or(nums: Vec<i32>, k: i32) -> i64 {
      let n = nums.len();
      let mut suf = vec![0 as i64;n];
      if n > 1 {
          for i in (0..=n.saturating_sub(2)).rev() {
              suf[i] = suf[i + 1] | nums[i + 1] as i64;
          }
      }
      let (mut pre, mut ans) = (0 as i64, 0 as i64);
      for i in 0..n {
          ans = ans.max(pre | (nums[i] as i64) << k | suf[i]);
          pre |= nums[i] as i64;
      }
      ans
  }
}
