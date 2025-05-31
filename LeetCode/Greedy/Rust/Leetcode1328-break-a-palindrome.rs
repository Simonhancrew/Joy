impl Solution {
  pub fn break_palindrome(mut s: String) -> String {
    let n = s.len();
    if n == 1 {
      return "".to_string();
    }
    let mut vec_char: Vec<char> = s.chars().collect();
    for i in 0..n / 2 {
      if vec_char[i] != 'a' {
        vec_char[i] = 'a';
        return vec_char.into_iter().collect();
      }
    }
    vec_char[n - 1] = 'b';
    vec_char.into_iter().collect()
  }
}
