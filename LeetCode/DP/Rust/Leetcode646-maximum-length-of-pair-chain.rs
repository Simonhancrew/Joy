impl Solution {
  pub fn find_longest_chain(mut pairs: Vec<Vec<i32>>) -> i32 {
    pairs.sort();
    let n = pairs.len();
    let (mut f, mut ans) = (vec![1; n], 1);
    for i in 1..n {
      for j in 0..i {
        if pairs[i][0] > pairs[j][1] {
          f[i] = f[i].max(f[j] + 1);
        }
      }
      ans = ans.max(f[i]);
    }
    ans
  }
}
