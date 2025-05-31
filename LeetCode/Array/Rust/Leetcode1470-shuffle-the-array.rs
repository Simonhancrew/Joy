impl Solution {
  pub fn shuffle(nums: Vec<i32>, n: i32) -> Vec<i32> {
    let n = n as usize;
    let mut ans = vec![0; n * 2];
    for i in 0..n {
      ans[i * 2] = nums[i];
      ans[i * 2 + 1] = nums[i + n];
    }
    ans
  }
}
