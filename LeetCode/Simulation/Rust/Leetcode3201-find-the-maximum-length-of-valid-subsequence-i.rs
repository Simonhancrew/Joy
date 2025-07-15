impl Solution {
  pub fn maximum_length(nums: Vec<i32>) -> i32 {
    let (mut x, mut y, mut t) = (0, 0, 0);
    for i in 0..nums.len() - 1 {
      if nums[i] & 1 == 1 {
        x += 1;
      } else {
        y += 1;
      }
      if nums[i] % 2 != nums[i + 1] % 2 {
        t += 1;
      }
    }
    if nums[nums.len() - 1] & 1 == 1 {
      x += 1;
    } else {
      y += 1;
    }
    x.max(y).max(t + 1)
  }
}
