use std::collections::VecDeque;
impl Solution {
  pub fn cut_off_tree(forest: Vec<Vec<i32>>) -> i32 {
    let (n, m) = (forest.len(), forest[0].len());
    let mut trees = Vec::new();
    for i in 0..n {
      for j in 0..m {
        if forest[i][j] > 1 {
          trees.push((forest[i][j], i, j));
        }
      }
    }

    let bfs = |st: (i32, usize, usize), ne: (i32, usize, usize)| -> i32 {
      if st.1 == ne.1 && st.2 == ne.2 {
        return 0;
      }
      let (dx, dy) = ([1, 0, -1, 0], [0, 1, 0, -1]);
      let (mut dist, mut q) = (vec![vec![1000000; m]; n], VecDeque::new());
      dist[st.1][st.2] = 0;
      q.push_back((st.1, st.2));
      while !q.is_empty() {
        let t = q.pop_front().unwrap();
        for i in 0..4 {
          let (nx, ny) = ((t.0 as i32 + dx[i]) as usize, (t.1 as i32 + dy[i]) as usize);
          if nx >= 0 && nx < n && ny >= 0 && ny < m && forest[nx][ny] != 0 {
            if dist[nx][ny] > dist[t.0][t.1] + 1 {
              dist[nx][ny] = dist[t.0][t.1] + 1;
              if nx == ne.1 && ny == ne.2 {
                return dist[nx][ny];
              }
              q.push_back((nx, ny));
            }
          }
        }
      }
      -1
    };

    trees.sort();

    // println!("{:?}",trees);

    let mut st = (0, 0, 0);
    let mut res = 0;
    for ne in trees {
      let t = bfs(st, ne);
      // println!("{}",t);
      if t == -1 {
        return -1;
      }
      res += t;
      st = ne;
    }
    res
  }
}
