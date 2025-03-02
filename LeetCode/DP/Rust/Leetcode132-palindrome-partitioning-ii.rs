impl Solution {
  fn check(s: &str, i: usize, j: usize, ff: &mut Vec<Vec<i32>>) -> bool {
      if i >= j {
          return true;
      }
      if ff[i][j] != -1 {
          return ff[i][j] == 1;
      }
      ff[i][j] = if s.as_bytes()[i] == s.as_bytes()[j] {
          Self::check(s, i + 1, j - 1, ff) as i32
      } else {
          0
      };
      ff[i][j] == 1
  }

  fn dfs(s: &str, i: usize, f: &mut Vec<i32>, ff: &mut Vec<Vec<i32>>) -> i32 {
      if i == s.len() {
          return 0;
      }
      if f[i] != -1 {
          return f[i];
      }
      let mut res = i32::MAX;
      for j in i..s.len() {
          if Self::check(s, i, j, ff) {
              res = res.min(Self::dfs(s, j + 1, f, ff) + 1);
          }
      }
      f[i] = res;
      f[i]
  }

  pub fn min_cut(s: String) -> i32 {
      let n = s.len();
      let mut f = vec![-1; n];
      let mut ff = vec![vec![-1; n]; n];
      Self::dfs(&s, 0, &mut f, &mut ff) - 1
  }
}
