impl Solution {
  fn gcd(a: i32, b: i32) -> i32 {
    if b == 0 {
      a
    } else {
      Self::gcd(b, a % b)
    }
  }
  pub fn smallest_even_multiple(n: i32) -> i32 {
    n * 2 / Self::gcd(n, 2)
  }
}
