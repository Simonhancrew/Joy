impl Solution {
  pub fn num_special(mat: Vec<Vec<i32>>) -> i32 {
    let (n, m) = (mat.len(), mat[0].len());
    let (mut r, mut c) = (vec![0; n], vec![0; m]);
    for i in 0..n {
      for j in 0..m {
        r[i] += mat[i][j];
        c[j] += mat[i][j];
      }
    }
    let mut ans = 0;
    for i in 0..n {
      for j in 0..m {
        if mat[i][j] == 1 && c[j] == 1 && r[i] == 1 {
          ans += 1
        }
      }
    }
    ans
  }
}
