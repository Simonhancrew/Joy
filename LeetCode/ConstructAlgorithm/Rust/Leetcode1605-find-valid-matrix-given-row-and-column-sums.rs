impl Solution {
  pub fn restore_matrix(mut row_sum: Vec<i32>, mut col_sum: Vec<i32>) -> Vec<Vec<i32>> {
    let (n, m) = (row_sum.len(), col_sum.len());
    let mut res = vec![vec![0; m]; n];
    for i in 0..n {
      for j in 0..m {
        let cur = row_sum[i].min(col_sum[j]);
        res[i][j] = cur;
        row_sum[i] -= cur;
        col_sum[j] -= cur;
      }
    }
    res
  }
}
