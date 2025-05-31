impl Solution {
  fn get(s: &str, ff: &mut Vec<Vec<i32>>, l: usize, r: usize) -> i32 {
    if l >= r {
      return 0;
    }
    if ff[l][r] != -1 {
      return ff[l][r];
    }
    ff[l][r] = Self::get(s, ff, l + 1, r - 1) + if s.as_bytes()[l] != s.as_bytes()[r] { 1 } else { 0 };
    ff[l][r]
  }
  fn dfs(s: &str, i: usize, k: usize, f: &mut Vec<Vec<i32>>, ff: &mut Vec<Vec<i32>>) -> i32 {
    if k == 1 {
      return Self::get(s, ff, i, s.len() - 1);
    }
    if f[i][k] != -1 {
      return f[i][k];
    }
    f[i][k] = 0x3f3f3f3f;
    for j in i..s.len() {
      if j + 1 == s.len() {
        break;
      }
      f[i][k] = f[i][k].min(Self::get(s, ff, i, j) + Self::dfs(s, j + 1, k - 1, f, ff));
    }
    f[i][k]
  }
  pub fn palindrome_partition(s: String, k: i32) -> i32 {
    let mut f = vec![vec![-1; k as usize + 1]; s.len()];
    let mut ff = vec![vec![-1; s.len()]; s.len()];
    Self::dfs(&s, 0, k as usize, &mut f, &mut ff)
  }
}
