impl Solution {
  pub fn merge_alternately(word1: String, word2: String) -> String {
    let n = word1.len().min(word2.len());
    let mut ans = String::new();
    for i in 0..n {
      ans += &word1[i..i + 1];
      ans += &word2[i..i + 1];
    }
    if n != word1.len() {
      ans += &word1[n..];
    }
    if n != word2.len() {
      ans += &word2[n..];
    }
    ans
  }
}
