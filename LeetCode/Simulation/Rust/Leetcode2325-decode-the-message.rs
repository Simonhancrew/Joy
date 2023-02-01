impl Solution {
  pub fn decode_message(key: String, mut message: String) -> String {
      use std::collections::HashMap;
      let mut mp = HashMap::new();
      let mut idx = b'a';
      for c in key.chars() {
          if c == ' ' || mp.contains_key(&c) {
              continue;
          } 
          mp.insert(c, idx as char);
          idx += 1;
      }
      let mut ans = String::new();
      for c in message.chars() {
          if mp.contains_key(&c) {
              ans.push(mp[&c]);
          }
          if c == ' ' {
              ans.push(' ');
          }
      }
      ans
  }
}