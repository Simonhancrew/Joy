use std::collections::HashMap;
// iter right, check left
impl Solution {
  pub fn max_operations(nums: Vec<i32>, k: i32) -> i32 {
    let mut mp = HashMap::new();
    let mut ans = 0;
    for x in nums {
      if x >= k {
        continue;
      }
      if let Some(v) = mp.get_mut(&x) {
        *v -= 1;
        ans += 1;
        if *v == 0 {
          mp.remove(&x);
        }
      } else {
        mp.entry(k - x).and_modify(|v| *v += 1).or_insert(1);
      }
    }
    ans
  }
}
