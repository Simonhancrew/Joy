impl Solution {
  pub fn min_operations(mut nums: Vec<i32>) -> i32 {
    if nums.len() == 1 {
      return 0;
    }
    let mut res = 0;
    for i in 1..nums.len() {
      if nums[i - 1] >= nums[i] {
        res += nums[i - 1] - nums[i] + 1;
        nums[i] = nums[i - 1] + 1;
      }
    }
    res
  }
}
