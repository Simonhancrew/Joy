impl Solution {
  pub fn row_and_maximum_ones(mat: Vec<Vec<i32>>) -> Vec<i32> {
    let (mut ans, mut cnt) = (0, 0);
    for i in 0..mat.len() {
      let cur = mat[i].iter().sum();
      if cur > cnt {
        ans = i as i32;
        cnt = cur;
      }
    }
    vec![ans, cnt]
  }
}
