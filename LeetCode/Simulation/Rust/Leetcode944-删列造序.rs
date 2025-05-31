impl Solution {
  pub fn min_deletion_size(strs: Vec<String>) -> i32 {
    let (n, m) = (strs.len(), strs[0].len());
    let mut res = 0;
    for j in 0..m {
      for i in 1..n {
        if strs[i - 1][j..(j + 1)] > strs[i][j..(j + 1)] {
          res += 1;
          break;
        }
      }
    }
    res
  }
}
