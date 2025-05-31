use std::collections::HashMap;
impl Solution {
  pub fn is_alien_sorted(words: Vec<String>, order: String) -> bool {
    let mut mp = HashMap::new();
    for i in 0..order.len() {
      mp.insert(&order[i..i + 1], i);
    }
    for i in 1..words.len() {
      let (l, r) = (&words[i - 1], &words[i]);
      let (mut x, mut y) = (0, 0);
      while x < l.len() && y < r.len() {
        if mp[&l[x..x + 1]] > mp[&r[y..y + 1]] {
          return false;
        }
        if mp[&l[x..x + 1]] < mp[&r[y..y + 1]] {
          break;
        }
        x += 1;
        y += 1;
      }
      if x < l.len() && y == r.len() {
        return false;
      }
    }
    true
  }
}
