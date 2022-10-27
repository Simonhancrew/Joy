impl Solution {
  pub fn array_sign(nums: Vec<i32>) -> i32 {
      let (mut nag, n) = (0, nums.len());
      for i in 0..n {
          if nums[i] == 0 {
              return 0;
          }
          if nums[i] < 0 {
              nag += 1;
          }
      }
      if nag % 2 == 1 {
          return -1;
      } 
      1
  }
}