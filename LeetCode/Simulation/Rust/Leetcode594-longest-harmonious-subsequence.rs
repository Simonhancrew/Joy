use std::collections::HashMap;
impl Solution {
  pub fn find_lhs(nums: Vec<i32>) -> i32 {
    let mut mp = HashMap::new();
    for x in nums {
      mp.entry(x).and_modify(|x| *x += 1).or_insert(1);
    }
    let mut ans = 0;
    for (k, v) in &mp {
      if let Some(ne) = mp.get(&(k + 1)) {
        ans = ans.max(v + ne);
      }
    }
    ans
  }
}
