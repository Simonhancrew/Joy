impl Solution {
  pub fn convert_temperature(celsius: f64) -> Vec<f64> {
    let mut ans = vec![0f64; 2];
    ans[0] = celsius + 273.15f64;
    ans[1] = celsius * 1.8f64 + 32.0f64;
    ans
  }
}
