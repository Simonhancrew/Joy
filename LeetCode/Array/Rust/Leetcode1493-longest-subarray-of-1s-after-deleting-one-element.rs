impl Solution {
  pub fn longest_subarray(nums: Vec<i32>) -> i32 {
    let (mut ans, mut l, mut cnt, mut l0) = (0, 0, 0, 0);
    for i in 0..nums.len() {
      if nums[i] == 0 {
        cnt += 1;
        if cnt > 1 {
          cnt -= 1;
          l = l0 + 1;
          l0 = i;
          continue;
        }
        l0 = i;
      }
      ans = ans.max(i - l);
    }
    ans as _
  }
}
