impl Solution {
  pub fn find_diagonal_order(mat: Vec<Vec<i32>>) -> Vec<i32> {
    let mut res = vec![];
    let (n, m) = (mat.len(), mat[0].len());
    for k in 0..=(m + n - 2) {
      let (min_j, max_j) = (if k + 1 < n { 0 } else { k - n + 1 }, (m - 1).min(k));
      if k % 2 == 0 {
        for j in min_j..=max_j {
          res.push(mat[k - j][j]);
        }
      } else {
        for j in (min_j..=max_j).rev() {
          res.push(mat[k - j][j]);
        }
      }
    }
    res
  }
}
