impl Solution {
  pub fn lucky_numbers(matrix: Vec<Vec<i32>>) -> Vec<i32> {
    let (n, m) = (matrix.len(), matrix[0].len());
    let (mut row, mut col) = (vec![100005; n], vec![0; m]);
    for i in 0..n {
      for j in 0..m {
        row[i] = row[i].min(matrix[i][j]);
        col[j] = col[j].max(matrix[i][j]);
      }
    }
    let mut ans = Vec::new();
    for i in 0..n {
      for j in 0..m {
        if row[i] == matrix[i][j] && matrix[i][j] == col[j] {
          ans.push(row[i]);
        }
      }
    }
    ans
  }
}
