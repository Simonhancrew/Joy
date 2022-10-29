impl Solution {
  pub fn count_matches(items: Vec<Vec<String>>, rule_key: String, rule_value: String) -> i32 {
      let (n, mut ans, mut key) = (items.len(), 0, 0);
      if &rule_key == "color" {
          key = 1;
      } else if &rule_key == "name" {
          key = 2;
      }
      for i in 0..n {
          if &items[i][key] == &rule_value {
              ans += 1;
          }
      }
      ans
  }
}