impl Solution {
  pub fn missing_two(nums: Vec<i32>) -> Vec<i32> {
    let n = nums.len() + 2;
    let (mut ans, mut acc) = (vec![0; 2], 0);
    for num in &nums {
      acc ^= num;
    }
    for i in 1..=n {
      acc ^= i as i32;
    }
    let lowbit = (acc) & (-acc);
    for num in &nums {
      if num & lowbit != 0 {
        ans[0] ^= num;
      } else {
        ans[1] ^= num;
      }
    }
    for i in 1..=n {
      if (i as i32) & lowbit != 0 {
        ans[0] ^= (i as i32);
      } else {
        ans[1] ^= (i as i32);
      }
    }
    ans
  }
}
