use std::collections::HashMap;
impl Solution {
  pub fn num_identical_pairs(nums: Vec<i32>) -> i32 {
    let mut mp = HashMap::new();
    let mut ans = 0;
    for x in &nums {
      if mp.contains_key(x) {
        ans += mp[x];
      }
      mp.entry(x).and_modify(|tar| *tar += 1).or_insert(1);
    }
    ans
  }
}
