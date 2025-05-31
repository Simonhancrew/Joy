impl Solution {
  pub fn check_powers_of_three(mut n: i32) -> bool {
    if n == 3 || n == 1 {
      return true;
    }
    if n % 3 == 2 {
      return false;
    }
    Self::check_powers_of_three(n - 1) || Self::check_powers_of_three(n / 3)
  }
}
