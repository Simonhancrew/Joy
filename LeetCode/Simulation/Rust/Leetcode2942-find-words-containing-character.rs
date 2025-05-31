impl Solution {
  pub fn find_words_containing(words: Vec<String>, x: char) -> Vec<i32> {
    let mut ans = vec![];
    for i in 0..words.len() {
      if words[i].contains(x) {
        ans.push(i as i32);
      }
    }
    ans
  }
}
