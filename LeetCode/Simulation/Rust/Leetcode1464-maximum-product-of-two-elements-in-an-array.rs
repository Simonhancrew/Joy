impl Solution {
  pub fn max_product(nums: Vec<i32>) -> i32 {
    let (mut mx, n) = (-1, nums.len());
    for i in 0..n {
      for j in i + 1..n {
        mx = mx.max((nums[i] - 1) * (nums[j] - 1));
      }
    }
    mx
  }
}
