impl Solution {
  pub fn subset_xor_sum(nums: Vec<i32>) -> i32 {
      fn dfs(nums: &[i32], i: usize, acc: i32, sum: &mut i32) {
          if (i >= nums.len()) {
              *sum += acc;
              return;
          }
          dfs(nums, i + 1, acc ^ nums[i], sum);
          dfs(nums, i + 1, acc, sum);
      }
      let mut sum = 0;
      dfs(&nums, 0, 0, &mut sum);
      sum
  }
}
