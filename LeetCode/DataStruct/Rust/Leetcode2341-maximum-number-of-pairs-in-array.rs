impl Solution {
  pub fn number_of_pairs(nums: Vec<i32>) -> Vec<i32> {
    use std::collections::HashMap;
    let mut mp = HashMap::new();
    for num in &nums {
      mp.entry(num).and_modify(|val| *val += 1).or_insert(1);
    }
    let mut ans = vec![0, nums.len() as i32];
    for num in &nums {
      if mp[num] >= 2 {
        ans[0] += 1;
        ans[1] -= 2;
        mp.entry(num).and_modify(|val| *val -= 2);
      }
    }
    ans
  }
}
