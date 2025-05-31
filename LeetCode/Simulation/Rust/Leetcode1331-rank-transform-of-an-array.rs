use std::collections::HashMap;
impl Solution {
  pub fn array_rank_transform(arr: Vec<i32>) -> Vec<i32> {
    let (n, mut tmp) = (arr.len(), arr.clone());
    tmp.sort();
    let mut mp = HashMap::new();
    let mut cnt = 1;
    for i in 0..n {
      if mp.contains_key(&tmp[i]) {
        continue;
      }
      mp.insert(tmp[i], cnt);
      cnt += 1;
    }
    let mut ans = vec![0; n];
    for i in 0..n {
      ans[i] = mp[&arr[i]]
    }
    ans
  }
}
