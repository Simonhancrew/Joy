impl Solution {
  pub fn max_distance(arrays: Vec<Vec<i32>>) -> i32 {
    let (mut ans, mut mx, mut mn) = (0, i32::MIN / 2, i32::MAX / 2);
    for x in &arrays {
      ans = ans.max(mx - x[0]).max(x[x.len() - 1] - mn);
      mx = mx.max(x[x.len() - 1]);
      mn = mn.min(x[0]);
    }
    ans
  }
}
