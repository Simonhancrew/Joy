impl Solution {
  pub fn longest_arith_seq_length(nums: Vec<i32>) -> i32 {
    let (mut mx, mut mn) = (-1, i32::MAX);
    for &x in nums.iter() {
      if x > mx {
        mx = x;
      }
      if x < mn {
        mn = x;
      }
    }
    let (n, mut res) = (nums.len(), 2);
    let mut f = vec![vec![0; 2 * (mx - mn) as usize + 1]; n];
    for i in 0..n {
      for j in 0..i {
        let diff = (nums[i] - nums[j] + mx - mn) as usize;
        f[i][diff] = f[i][diff].max(2);
        f[i][diff] = f[i][diff].max(f[j][diff] + 1);
        res = res.max(f[i][diff]);
      }
    }
    res
  }
}
