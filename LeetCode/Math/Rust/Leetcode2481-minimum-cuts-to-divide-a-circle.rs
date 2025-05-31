impl Solution {
  pub fn number_of_cuts(n: i32) -> i32 {
    if n == 1 {
      return 0;
    }
    if n & 1 == 1 {
      return n;
    }
    n / 2
  }
}
