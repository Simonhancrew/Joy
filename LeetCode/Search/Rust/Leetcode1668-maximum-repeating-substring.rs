impl Solution {
  pub fn max_repeating(sequence: String, word: String) -> i32 {
    let (mut l, mut r) = (0, sequence.len() / word.len());
    while l < r {
      let mid = (l + r + 1) >> 1;
      let s = word.repeat(mid);
      if sequence.contains(&s) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    l as i32
  }
}
