impl Solution {
  pub fn distribute_candies(n: i32, limit: i32) -> i64 {
    let c2 = |x| -> i64 {
      let x = x as i64;
      if x > 1 {
        (x * (x - 1) / 2) as _
      } else {
        0
      }
    };
    c2(n + 2) - 3 * c2(n - limit + 1) + 3 * c2(n - 2 * limit) - c2(n - 3 * limit - 1)
  }
}
