impl Solution {
  pub fn maximum_triplet_value(nums: Vec<i32>) -> i64 {
    let mut ans = 0i64;
    let n = nums.len();
    for i in 0..n - 2 {
      for j in i + 1..n - 1 {
        for k in j + 1..n {
          ans = ans.max((nums[i] - nums[j]) as i64 * nums[k] as i64);
        }
      }
    }
    ans
  }
}
