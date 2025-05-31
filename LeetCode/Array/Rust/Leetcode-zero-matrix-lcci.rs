impl Solution {
  pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
    let (n, m) = (matrix.len(), matrix[0].len());
    let (mut r, mut c) = (vec![false; n], vec![false; m]);
    for i in 0..n {
      for j in 0..m {
        if matrix[i][j] == 0 {
          r[i] = true;
          c[j] = true;
        }
      }
    }
    for i in 0..n {
      for j in 0..m {
        if r[i] || c[j] {
          matrix[i][j] = 0;
        }
      }
    }
  }
}
