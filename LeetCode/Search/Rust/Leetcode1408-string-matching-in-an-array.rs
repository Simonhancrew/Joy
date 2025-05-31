impl Solution {
  pub fn string_matching(words: Vec<String>) -> Vec<String> {
    let mut ans = vec![];
    let n = words.len();
    for i in 0..n {
      for j in 0..n {
        if i != j && !words[j].find(&words[i]).is_none() {
          ans.push(words[i].clone());
          break;
        }
      }
    }
    ans
  }
}
