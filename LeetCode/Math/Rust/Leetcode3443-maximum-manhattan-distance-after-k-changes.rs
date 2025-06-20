use std::collections::HashMap;
impl Solution {
  pub fn max_distance(s: String, k: i32) -> i32 {
    let (mut mp, mut res) = (HashMap::new(), 0);
    let func = |a: i32, b: i32, left: &mut i32| -> i32 {
      let d = (*left).min(a).min(b);
      *left -= d;
      (a - b).abs() + 2 * d
    };
    for c in s.chars() {
      *mp.entry(c).or_insert(0) += 1;
      let n = *mp.get(&'N').unwrap_or(&0);
      let s = *mp.get(&'S').unwrap_or(&0);
      let e = *mp.get(&'E').unwrap_or(&0);
      let w = *mp.get(&'W').unwrap_or(&0);
      let mut left = k;
      let dist = func(n, s, &mut left) + func(e, w, &mut left);
      res = res.max(dist);
    }
    res
  }
}
