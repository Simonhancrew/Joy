impl Solution {
  pub fn count_subarrays(nums: Vec<i32>, k: i32) -> i64 {
      let (mut ans, mut cnt) = (0i64, 0);
      let (tar, mut l) = (*nums.iter().max().unwrap(), 0usize);
      for r in 0..nums.len() {
          if nums[r] == tar {
              cnt += 1;
          }
          while l <= r && cnt >= k {
              if nums[l] == tar {
                  cnt -= 1;
              }
              l += 1;
          }
          ans += l as i64;
      }
      ans
  }
}
