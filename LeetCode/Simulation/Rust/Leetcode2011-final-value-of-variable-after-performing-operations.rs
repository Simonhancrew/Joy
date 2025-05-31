impl Solution {
  pub fn final_value_after_operations(operations: Vec<String>) -> i32 {
    let mut ans = 0;
    for x in &operations {
      if b'-' == x.as_bytes()[0] || b'-' == x.as_bytes()[2] {
        ans -= 1;
      } else {
        ans += 1;
      }
    }
    ans
  }
}
