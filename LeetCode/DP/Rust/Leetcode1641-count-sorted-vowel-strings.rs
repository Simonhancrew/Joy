impl Solution {
  pub fn count_vowel_strings(n: i32) -> i32 {
      let mut f = vec![vec![-1;5];n as usize + 1];
      let mut ans = 0;
      fn dfs(n : usize, c : usize, f: &mut Vec<Vec<i32>>) -> i32 {
          if n == 1 {
              return 1;
          }
          if f[n][c] != -1 {
              return f[n][c];
          } 
          let mut ans = 0;
          for i in c..5 {
              ans += dfs(n - 1, i, f);
          }
          f[n][c] = ans;
          ans as i32 
      }
      for i in 0..5 {
          ans += dfs(n as usize, i, &mut f);
      }
      ans
  }
}