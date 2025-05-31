impl Solution {
  pub fn calculate_tax(brackets: Vec<Vec<i32>>, income: i32) -> f64 {
    let (mut ans, mut pre) = (0 as f64, 0 as i32);
    for x in &brackets {
      if income >= x[0] {
        ans += ((x[0] - pre) * x[1]) as f64 / 100.0;
        pre = x[0];
      } else {
        ans += ((income - pre) * x[1]) as f64 / 100.0;
        break;
      }
    }
    ans
  }
}
