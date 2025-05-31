use std::collections::VecDeque;
impl Solution {
  pub fn count_palindromic_subsequences(s: String) -> i32 {
    const P: i32 = 1e9 as i32 + 7;
    let n = s.len();
    let mut f = vec![vec![1; n + 1]; n + 1];
    for i in 1..=n {
      f[i][i] += 1;
    }
    for length in 2..=n {
      let mut q = vec![VecDeque::new(); 4];
      for j in 1..=n {
        q[(s.as_bytes()[j - 1] - 'a' as u8) as usize].push_back(j);
        if j < length {
          continue;
        }
        let i = j - length + 1;
        for k in 0..4 {
          while !q[k].is_empty() && q[k][0] < i {
            q[k].pop_front();
          }
          if !q[k].is_empty() {
            f[i][j] += 1;
            let (l, r) = (q[k].front().unwrap(), q[k].back().unwrap());
            if l < r {
              f[i][j] = (f[i][j] + f[l + 1][r - 1]) % P;
            }
          }
        }
      }
    }
    (f[1][n] - 1 + P) % P
  }
}
