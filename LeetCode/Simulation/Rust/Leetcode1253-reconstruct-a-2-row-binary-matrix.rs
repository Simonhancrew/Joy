impl Solution {
  pub fn reconstruct_matrix(mut upper: i32, mut lower: i32, colsum: Vec<i32>) -> Vec<Vec<i32>> {
    let n = colsum.len();
    let (mut sum, mut rec) = (0, 0);
    for &x in &colsum {
      if x == 2 {
        rec += 1;
      }
      sum += x;
    }
    if sum != upper + lower || rec > upper.min(lower) {
      return Vec::new();
    }
    upper -= rec;
    lower -= rec;
    let mut res = vec![vec![0; n]; 2];
    for i in 0..n {
      if colsum[i] == 2 {
        res[0][i] = 1;
        res[1][i] = 1;
      } else if colsum[i] == 1 {
        if upper > 0 {
          res[0][i] = 1;
          upper -= 1;
        } else {
          res[1][i] = 1;
          lower -= 1;
        }
      }
    }
    res
  }
}
