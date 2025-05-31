// 左边递增，右边递减
impl Solution {
  pub fn min_operations(nums: Vec<i32>, x: i32) -> i32 {
    let (mut lhs, mut rhs, n, mut ans): (i32, i32, usize, i32) = (0, nums.iter().sum(), nums.len(), i32::MAX);
    if rhs < x {
      return -1;
    }
    let mut r = 0;
    for l in -1..(n as i32) {
      if l != -1 {
        lhs += nums[l as usize];
      }
      while r < n && lhs + rhs > x {
        rhs -= nums[r];
        r += 1;
      }
      if lhs + rhs == x {
        ans = ans.min(l + 1 + (n - r) as i32);
      }
    }
    if ans == i32::MAX {
      return -1;
    }
    ans
  }
}
