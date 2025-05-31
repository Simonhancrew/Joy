impl Solution {
  fn is_prime(x: i32) -> bool {
    let mut i = 2;
    while i * i <= x {
      if x % i == 0 {
        return false;
      }
      i += 1;
    }
    x >= 2
  }
  pub fn diagonal_prime(nums: Vec<Vec<i32>>) -> i32 {
    let (mut n, mut res) = (nums.len(), 0);
    for i in 0..n {
      for x in [nums[i][i], nums[i][n - 1 - i]] {
        if x > res && Self::is_prime(x) {
          res = x;
        }
      }
    }
    res
  }
}
