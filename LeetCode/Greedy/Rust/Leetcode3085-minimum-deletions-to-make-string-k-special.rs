impl Solution {
  pub fn minimum_deletions(word: String, k: i32) -> i32 {
    let mut cnt = vec![0usize; 26];
    for x in word.as_bytes() {
      cnt[(x - b'a') as usize] += 1;
    }
    cnt.sort_unstable();
    let mut res = 0;
    for i in 0..26 {
      let mut acc = 0;
      for j in i..26 {
        acc += cnt[j].min(cnt[i] + k as usize);
      }
      res = res.max(acc);
    }
    (word.len() - res) as _
  }
}
