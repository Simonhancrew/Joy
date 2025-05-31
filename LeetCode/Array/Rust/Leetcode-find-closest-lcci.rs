impl Solution {
  pub fn find_closest(words: Vec<String>, word1: String, word2: String) -> i32 {
    let (n, mut l, mut r, mut ans) = (words.len(), -1, -1, 10000);
    for i in 0..n {
      if words[i] == word1 {
        l = i as i32;
      }
      if words[i] == word2 {
        r = i as i32;
      }
      if l >= 0 && r >= 0 {
        ans = ans.min((r - l).abs());
      }
    }
    ans
  }
}
