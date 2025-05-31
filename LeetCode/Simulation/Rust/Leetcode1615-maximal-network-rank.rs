impl Solution {
  pub fn maximal_network_rank(n: i32, roads: Vec<Vec<i32>>) -> i32 {
    use std::collections::HashSet;
    let mut g = vec![HashSet::new(); n as usize];
    for r in &roads {
      g[r[0] as usize].insert(r[1]);
      g[r[1] as usize].insert(r[0]);
    }
    let mut res = 0;
    for i in 0..n {
      for j in i + 1..n {
        let mut cur = g[i as usize].len() + g[j as usize].len();
        if g[i as usize].contains(&j) {
          cur -= 1;
        }
        res = res.max(cur);
      }
    }
    res as i32
  }
}
