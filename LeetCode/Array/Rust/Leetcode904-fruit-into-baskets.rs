use std::collections::HashMap;
impl Solution {
  pub fn total_fruit(fruits: Vec<i32>) -> i32 {
    let (mut mp, mut l) = (HashMap::new(), 0);
    let mut ans = 0;
    for i in 0..fruits.len() {
      mp.entry(fruits[i]).and_modify(|v| *v += 1).or_insert(1);
      while mp.len() > 2 {
        mp.entry(fruits[l]).and_modify(|v| *v -= 1);
        if mp[&fruits[l]] == 0 {
          mp.remove(&fruits[l]);
        }
        l += 1;
      }
      ans = ans.max(i - l + 1);
    }
    ans as _
  }
}
