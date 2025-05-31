use std::cmp::Reverse;
use std::collections::BinaryHeap;
impl Solution {
  pub fn min_time_to_reach(mut move_time: Vec<Vec<i32>>) -> i32 {
    let mut heap = BinaryHeap::new();
    let (n, m) = (move_time.len(), move_time[0].len());
    let (dx, dy): ([i32; 4], [i32; 4]) = ([0, 1, 0, -1], [1, 0, -1, 0]);
    heap.push((Reverse(0), 0, 1));
    while !heap.is_empty() {
      let (Reverse(d), t, add) = heap.pop().unwrap();
      let (x, y) = (t / m, t % m);
      if move_time[x][y] < 0 {
        continue;
      }
      if x == n - 1 && y == m - 1 {
        return d;
      }
      move_time[x][y] = -1;
      for i in 0..4 {
        let (nx, ny) = (x as i32 + dx[i], y as i32 + dy[i]);
        if nx < 0 || nx >= n as i32 || ny < 0 || ny >= m as i32 || move_time[nx as usize][ny as usize] < 0 {
          continue;
        }
        let mut nd = move_time[nx as usize][ny as usize];
        if d >= nd {
          nd = d + add;
        } else {
          nd += add;
        }
        heap.push((Reverse(nd), nx as usize * m + ny as usize, add ^ 3));
      }
    }
    -1
  }
}
