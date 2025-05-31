impl Solution {
  pub fn max_rotate_function(nums: Vec<i32>) -> i32 {
    let acc: i32 = nums.iter().sum();
    let n = nums.len();
    let mut res = 0;
    for i in 0..n {
      res += nums[i] * (i as i32);
    }
    let mut f = res;
    for i in (0..n).rev() {
      f += acc - (n as i32) * nums[i];
      res = res.max(f);
    }
    res
  }
}
