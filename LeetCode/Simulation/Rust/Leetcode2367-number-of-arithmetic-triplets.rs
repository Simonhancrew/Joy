impl Solution {
  pub fn arithmetic_triplets(nums: Vec<i32>, diff: i32) -> i32 {
    use std::collections::HashSet;
    let mut st = HashSet::new();
    for x in nums.iter() {
      st.insert(x);
    }
    let mut ans = 0;
    for x in nums.iter() {
      if st.contains(&(x + diff)) && st.contains(&(x + 2 * diff)) {
        ans += 1;
      }
    }
    ans
  }
}
