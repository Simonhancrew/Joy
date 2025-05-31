impl Solution {
  fn check(s: &str) -> bool {
    let mut chars = s.chars();
    while let (Some(left), Some(right)) = (chars.next(), chars.next_back()) {
      if left != right {
        return false;
      }
    }
    true
  }
  fn dfs(i: usize, s: &str, res: &mut Vec<Vec<String>>, cur: &mut Vec<String>) {
    if i == s.len() {
      res.push(cur.clone());
      return;
    }
    for j in i..s.len() {
      if Self::check(&s[i..=j]) {
        cur.push((&s[i..=j]).to_string());
        Self::dfs(j + 1, s, res, cur);
        cur.pop();
      }
    }
  }
  pub fn partition(s: String) -> Vec<Vec<String>> {
    let mut res = Vec::new();
    let mut cur = Vec::new();
    Self::dfs(0, &s, &mut res, &mut cur);
    res
  }
}
