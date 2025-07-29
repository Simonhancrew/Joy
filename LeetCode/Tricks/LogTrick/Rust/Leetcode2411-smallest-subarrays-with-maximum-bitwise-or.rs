impl Solution {
  pub fn smallest_subarrays(mut nums: Vec<i32>) -> Vec<i32> {
    let mut ans = vec![1; nums.len()];
    for i in 0..nums.len() {
      let mut j = i - 1;
      while j != usize::MAX && nums[j] | nums[i] != nums[j] {
        nums[j] |= nums[i];
        ans[j] = (i - j + 1) as i32;
        j -= 1;
      }
    }
    ans
  }
}
