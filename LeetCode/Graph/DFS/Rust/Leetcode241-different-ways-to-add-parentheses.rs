impl Solution {
  pub fn diff_ways_to_compute(expression: String) -> Vec<i32> {
    let (mut res, n) = (vec![], expression.len());
    if n == 0 {
      return res;
    }
    let chars = expression.as_bytes();
    for i in 0..n {
      match chars[i] {
        b'+' | b'-' | b'*' => {
          let left = Self::diff_ways_to_compute(expression[..i].to_owned());
          let right = Self::diff_ways_to_compute(expression[i + 1..].to_owned());
          for lhs in &left {
            for rhs in &right {
              match chars[i] {
                b'+' => res.push(lhs + rhs),
                b'-' => res.push(lhs - rhs),
                _ => res.push(lhs * rhs),
              }
            }
          }
        }
        _ => continue,
      }
    }
    if res.is_empty() {
      res.push(expression.parse::<i32>().unwrap());
    }
    res
  }
}
