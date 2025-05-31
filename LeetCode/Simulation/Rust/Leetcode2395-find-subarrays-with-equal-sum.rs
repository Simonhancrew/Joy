impl Solution {
  pub fn find_subarrays(nums: Vec<i32>) -> bool {
    use std::collections::HashSet;
    let mut st = HashSet::new();
    for i in 1..nums.len() {
      let cur = nums[i - 1] + nums[i];
      if st.contains(&cur) {
        return true;
      }
      st.insert(cur);
    }
    false
  }
}
