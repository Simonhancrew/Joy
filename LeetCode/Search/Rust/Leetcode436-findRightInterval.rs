impl Solution {
  pub fn find_right_interval(intervals: Vec<Vec<i32>>) -> Vec<i32> {
    let (n, mut q) = (intervals.len(), intervals);
    let mut res: Vec<i32> = vec![-1; n];
    for i in 0..n {
      q[i].push(i as i32);
    }
    q.sort();
    for x in &q {
      let (mut l, mut r) = (0, n - 1);
      while l < r {
        let mid = (l + r) >> 1;
        if q[mid][0] >= x[1] {
          r = mid;
        } else {
          l = mid + 1;
        }
      }
      if q[l][0] >= x[1] {
        res[x[2] as usize] = q[l][2];
      }
    }
    res
  }
}
