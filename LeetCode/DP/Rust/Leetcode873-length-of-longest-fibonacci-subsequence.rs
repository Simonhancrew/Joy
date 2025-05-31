use std::collections::HashMap;
impl Solution {
  pub fn len_longest_fib_subseq(arr: Vec<i32>) -> i32 {
    let (n, mut res, mut mp) = (arr.len(), 0, HashMap::new());
    for i in 0..n {
      mp.insert(arr[i], i);
    }
    let mut f = vec![vec![0; n]; n];
    for i in 0..n {
      for j in 0..i {
        let x = arr[i] - arr[j];
        f[i][j] = 2;
        if x < arr[j] && mp.contains_key(&x) {
          let k = mp[&x];
          f[i][j] = f[i][j].max(f[j][k] + 1);
        }
        res = res.max(f[i][j]);
      }
    }
    if res < 3 {
      return 0;
    }
    res
  }
}
