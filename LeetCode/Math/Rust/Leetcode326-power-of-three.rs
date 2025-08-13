impl Solution {
  pub fn is_power_of_three(mut n: i32) -> bool {
    if n <= 0 {
      return false;
    }
    while n % 3 == 0 {
      n /= 3;
    }
    n == 1
  }
}
