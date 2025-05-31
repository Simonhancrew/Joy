impl Solution {
  pub fn find_and_replace_pattern(words: Vec<String>, pattern: String) -> Vec<String> {
    let (mut ans, n) = (Vec::new(), pattern.len());
    for s in words {
      if s.len() != n {
        continue;
      }
      let (mut mp, mut vis) = (vec![-1; 26], vec![false; 26]);
      let mut ok = true;
      for i in 0..n {
        let (l, r) = (
          (s.as_bytes()[i] - b'a') as usize,
          (pattern.as_bytes()[i] - b'a') as usize,
        );
        if mp[l] == -1 && !vis[r] {
          mp[l] = r as i32;
          vis[r] = true;
        } else if mp[l] != r as i32 {
          ok = false;
          break;
        }
      }
      if ok {
        ans.push(s);
      }
    }
    ans
  }
}
