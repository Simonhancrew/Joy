impl Solution {
  pub fn candy(ratings: Vec<i32>) -> i32 {
    let mut res = ratings.len() as i32;
    let (n, mut i) = (ratings.len(), 0);
    while i < n {
      let start = if i > 0 && ratings[i - 1] < ratings[i] { i - 1 } else { i };
      while i + 1 < n && ratings[i] < ratings[i + 1] {
        i += 1;
      }
      let top = i;
      while i + 1 < n && ratings[i] > ratings[i + 1] {
        i += 1;
      }
      let (inc, dec) = ((top - start) as i32, (i - top) as i32);
      res += ((inc - 1) * inc + (dec - 1) * dec) / 2 + inc.max(dec);
      i += 1;
    }
    res
  }
}
