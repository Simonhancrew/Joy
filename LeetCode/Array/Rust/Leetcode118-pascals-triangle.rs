impl Solution {
  pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
    let mut ans = vec![vec![]; num_rows as usize];
    for i in 0..num_rows as usize {
      ans[i].resize(i + 1, 1);
      // println!("{:?}", ans[i]);
      for j in 1..i {
        ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
      }
    }
    ans
  }
}
