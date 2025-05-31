impl Solution {
  pub fn can_partition(mut nums: Vec<i32>) -> bool {
    let total: i32 = nums.iter().sum();
    if nums.len() == 1 || total % 2 != 0 {
      return false;
    }
    nums.sort_unstable();
    let mut f = vec![vec![-1; (total / 2 + 1) as usize]; nums.len()];
    fn dfs(i: usize, j: usize, nums: &Vec<i32>, f: &mut Vec<Vec<i32>>) -> bool {
      if i >= nums.len() {
        return j == 0;
      }
      if f[i][j] != -1 {
        return if f[i][j] == 0 { false } else { true };
      }
      let mut res = dfs(i + 1, j, nums, f);
      if j >= nums[i] as usize {
        res |= dfs(i + 1, j - nums[i] as usize, nums, f);
      }
      f[i][j] = if res { 1 } else { 0 };
      if f[i][j] > 0 {
        true
      } else {
        false
      }
    }
    dfs(0, (total / 2) as usize, &nums, &mut f)
  }
}
