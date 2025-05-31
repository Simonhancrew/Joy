impl Solution {
  pub fn longest_decomposition(text: String) -> i32 {
    if text.len() == 0 {
      return 0;
    }
    let n = text.len();
    for i in 1..=(text.len() / 2) {
      if text[0..i] == text[(n - i)..n] {
        return 2 + Self::longest_decomposition(String::from(&text[i..n - i]));
      }
    }
    1
  }
}
