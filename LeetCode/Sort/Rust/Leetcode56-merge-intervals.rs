impl Solution {
  pub fn merge(mut intervals: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mut ans: Vec<Vec<i32>> = Vec::new();
    intervals.sort_unstable();
    for x in intervals {
      let n = ans.len();
      if !ans.is_empty() && ans[n - 1][1] >= x[0] {
        ans[n - 1][1] = x[1].max(ans[n - 1][1]);
      } else {
        ans.push(x);
      }
    }
    ans
  }
}
