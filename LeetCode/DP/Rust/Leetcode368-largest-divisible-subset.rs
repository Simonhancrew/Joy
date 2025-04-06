impl Solution {
  pub fn largest_divisible_subset(mut nums: Vec<i32>) -> Vec<i32> {
      nums.sort_unstable();
      let n = nums.len();
      let (mut f, mut to) = (vec![0;n], vec![n;n]);
      fn dfs(idx: usize, nums: &Vec<i32>, f: &mut Vec<i32>, to: &mut Vec<usize>) -> i32 {
          if f[idx] != 0 {
              return f[idx];
          }
          let n = nums.len();
          for i in idx + 1..n {
              if nums[i] % nums[idx] != 0 {
                  continue;
              }
              let cur = dfs(i, nums, f, to);
              if cur > f[idx] {
                  f[idx] = cur;
                  to[idx] = i;
              }
          }
          f[idx] += 1;
          return f[idx];
      }
      let (mut mx_res, mut mut_start) = (0, 0);
      for i in 0..n {
          let res = dfs(i, &nums, &mut f, &mut to);
          if res > mx_res {
              mx_res = res;
              mut_start = i;
          }
      }
      let mut res = vec![];
      let mut idx = mut_start;
      while idx < n {
          res.push(nums[idx]);
          idx = to[idx];
      }
      res
  }
}