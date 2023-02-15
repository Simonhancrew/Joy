impl Solution {
  fn gcd(a: i32, b: i32) -> i32 {
      if b == 0 {
          a
      } else {
          Self::gcd(b, a % b)
      }
  }
  pub fn is_good_array(nums: Vec<i32>) -> bool {
      let mut base = nums[0];
      for i in 1..nums.len() {
          base = Self::gcd(base, nums[i]);
          if base == 1 {
              break;
          }
      }
      base == 1
  }
}