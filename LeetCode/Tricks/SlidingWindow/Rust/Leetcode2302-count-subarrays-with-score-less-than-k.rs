impl Solution {
  pub fn count_subarrays(nums: Vec<i32>, k: i64) -> i64 {
      let (mut ans, mut acc) = (0i64, 0i64);
      let mut l = 0usize;
      for r in 0..nums.len() {
          acc += nums[r] as i64;
          while l <= r && acc * (r - l + 1) as i64 >= k {
              acc -= nums[l] as i64;
              l += 1;
          }
          ans += (r - l + 1) as i64;
      }
      ans
  }
}
