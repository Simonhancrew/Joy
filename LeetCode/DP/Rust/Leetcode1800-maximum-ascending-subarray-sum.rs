impl Solution {
  pub fn max_ascending_sum(nums: Vec<i32>) -> i32 {
    let n = nums.len();
    let (mut f, mut ans) = (vec![0; n], nums[0]);
    f[0] = nums[0];
    for i in 1..n {
      if nums[i] > nums[i - 1] {
        f[i] = f[i - 1] + nums[i];
      } else {
        f[i] = nums[i];
      }
      ans = ans.max(f[i]);
    }
    ans
  }
}
