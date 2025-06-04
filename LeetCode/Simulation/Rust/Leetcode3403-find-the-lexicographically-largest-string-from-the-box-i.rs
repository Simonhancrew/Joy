impl Solution {
  pub fn answer_string(word: String, num_friends: i32) -> String {
    if num_friends == 1 {
      return word;
    }
    let mut ans = String::new();
    for i in 0..word.len() {
      // n - (k - 1) => i + n - k + 1
      ans = ans.max(String::from(
        &word[i..word.len().min(i + word.len() - num_friends as usize + 1)],
      ));
    }
    ans
  }
}
