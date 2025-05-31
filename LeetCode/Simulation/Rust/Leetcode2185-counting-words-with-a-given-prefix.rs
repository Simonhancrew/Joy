impl Solution {
  pub fn prefix_count(words: Vec<String>, pref: String) -> i32 {
    let mut ans = 0;
    let check = |word: &str| -> bool {
      let word = word.as_bytes();
      let pref = pref.as_bytes();
      if word.len() < pref.len() {
        return false;
      }
      for i in 0..pref.len() {
        if word[i] != pref[i] {
          return false;
        }
      }
      true
    };
    for word in words {
      if check(&word) {
        ans += 1;
      }
    }
    ans
  }
}
