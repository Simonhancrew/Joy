use std::collections::HashMap;
impl Solution {
  pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut mp = HashMap::new();
    for i in 0..nums.len() {
      if mp.contains_key(&nums[i]) {
        return vec![mp[&nums[i]], i as i32];
      }
      mp.entry(target - nums[i])
        .and_modify(|x| *x = i as i32)
        .or_insert(i as i32);
    }
    vec![-1, -1]
  }
}
