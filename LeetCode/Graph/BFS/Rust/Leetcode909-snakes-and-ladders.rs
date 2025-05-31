use std::collections::VecDeque;
impl Solution {
  pub fn snakes_and_ladders(board: Vec<Vec<i32>>) -> i32 {
    let n = board.len();
    let (mut st, mut q) = (vec![false; n * n + 1], VecDeque::from([(1, 0)]));
    st[1] = true;
    while !q.is_empty() {
      if let Some((node, d)) = q.pop_front() {
        if node == n * n {
          return d;
        }
        for i in 1..=6 {
          let mut ne = node + i;
          if ne > n * n {
            continue;
          }
          let (r, mut c) = ((ne - 1) / n, (ne - 1) % n);
          if r % 2 == 1 {
            c = n - 1 - c;
          }
          if board[n - 1 - r][c] != -1 {
            ne = board[n - 1 - r][c] as usize;
          }
          if !st[ne] {
            st[ne] = true;
            q.push_back((ne, d + 1));
          }
        }
      }
    }
    -1
  }
}
