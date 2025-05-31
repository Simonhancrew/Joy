impl Solution {
  pub fn largest_merge(word1: String, word2: String) -> String {
    let (mut l, mut r) = (0, 0);
    let mut ans = String::new();
    while l < word1.len() && r < word2.len() {
      if word1.as_bytes()[l] > word2.as_bytes()[r] {
        ans.push(word1.as_bytes()[l] as char);
        l += 1;
      } else if word1.as_bytes()[l] < word2.as_bytes()[r] {
        ans.push(word2.as_bytes()[r] as char);
        r += 1;
      } else {
        if word1[l..] > word2[r..] {
          ans.push(word1.as_bytes()[l] as char);
          l += 1;
        } else {
          ans.push(word2.as_bytes()[r] as char);
          r += 1;
        }
      }
    }
    if l < word1.len() {
      ans += &word1[l..];
    }
    if r < word2.len() {
      ans += &word2[r..];
    }
    ans
  }
}
