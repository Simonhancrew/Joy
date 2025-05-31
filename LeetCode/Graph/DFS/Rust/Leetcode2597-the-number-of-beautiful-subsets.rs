use std::collections::HashMap;
impl Solution {
  pub fn beautiful_subsets(mut nums: Vec<i32>, k: i32) -> i32 {
    let mut mp: HashMap<i32, i32> = HashMap::new();
    let mut ans = -1;
    fn dfs(nums: &Vec<i32>, i: usize, ans: &mut i32, k: i32, mp: &mut HashMap<i32, i32>) {
      if i == nums.len() {
        *ans += 1;
        return;
      }
      dfs(nums, i + 1, ans, k, mp);
      let val = nums[i];
      let is_valid = mp.get(&(val + k)).map_or(true, |&v| v == 0) && mp.get(&(val - k)).map_or(true, |&v| v == 0);
      if is_valid {
        *mp.entry(val).or_insert(0) += 1;
        dfs(nums, i + 1, ans, k, mp);
        *mp.entry(val).or_insert(0) -= 1;
      }
    }
    dfs(&mut nums, 0, &mut ans, k, &mut mp);
    ans
  }
}
