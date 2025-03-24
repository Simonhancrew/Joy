impl Solution {
  pub fn count_prefixes(words: Vec<String>, s: String) -> i32 {
      words
          .iter()
          .filter(|x| s.starts_with(x.as_str()))
          .count() as i32
  }
}
