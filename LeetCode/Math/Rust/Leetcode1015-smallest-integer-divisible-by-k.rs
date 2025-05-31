impl Solution {
  pub fn smallest_repunit_div_by_k(k: i32) -> i32 {
    if k == 1 {
      return 1;
    }
    use std::collections::HashSet;
    let (mut ans, mut st, mut num) = (1, HashSet::new(), 1);
    loop {
      num = (num * 10 + 1) % k;
      ans += 1;
      if num == 0 {
        return ans;
      } else if st.contains(&num) {
        break;
      }
      st.insert(num);
    }
    -1
  }
}
