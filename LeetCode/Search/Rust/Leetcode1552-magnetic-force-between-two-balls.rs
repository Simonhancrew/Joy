impl Solution {
  pub fn max_distance(mut position: Vec<i32>, m: i32) -> i32 {
    position.sort_unstable();
    let n = position.len();
    let (mut l, mut r) = (0, (position[n - 1] - position[0]) / (m - 1) + 1);
    let f = |x: i32| -> i32 {
      let mut cnt = 1;
      let mut pre = position[0];
      for i in 1..position.len() {
        if position[i] - pre >= x {
          pre = position[i];
          cnt += 1;
        }
      }
      cnt
    };
    while (l + 1 < r) {
      let mid = (l + r) >> 1;
      if (f(mid) >= m) {
        l = mid;
      } else {
        r = mid;
      }
    }
    l
  }
}
