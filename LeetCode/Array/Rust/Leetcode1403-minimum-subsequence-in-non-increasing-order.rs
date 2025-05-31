impl Solution {
  pub fn min_subsequence(mut nums: Vec<i32>) -> Vec<i32> {
    let (mut ans, mut acc, mut sum) = (vec![], 0, nums.iter().sum());
    nums.sort_unstable();
    let n = nums.len();
    for i in (0..n).rev() {
      if acc > sum {
        break;
      }
      acc += nums[i];
      sum -= nums[i];
      ans.push(nums[i]);
    }
    ans
  }
}
