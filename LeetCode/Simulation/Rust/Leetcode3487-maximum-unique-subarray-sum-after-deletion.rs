use std::collections::HashSet;
impl Solution {
  pub fn max_sum(nums: Vec<i32>) -> i32 {
    let (mut st, mut mx, mut ans) = (HashSet::new(), -101, 0);
    for x in nums {
      if x < 0 {
        mx = mx.max(x);
      } else if st.insert(x) {
        ans += x;
      }
    }
    if st.is_empty() {
      mx
    } else {
      ans
    }
  }
}
