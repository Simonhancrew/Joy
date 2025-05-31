impl Solution {
  pub fn evaluate(s: String, knowledge: Vec<Vec<String>>) -> String {
    use std::collections::HashMap;
    let mut ans = String::new();
    let knowledge = knowledge
      .into_iter()
      .map(|v| (v[0].to_owned(), v[1].to_owned()))
      .collect::<HashMap<String, String>>();

    let mut flag = false;
    let mut cur = String::new();
    for ch in s.chars() {
      match ch {
        '(' => flag = true,
        ')' => {
          ans.push_str(knowledge.get(&cur).unwrap_or(&"?".to_string()));
          cur.clear();
          flag = false;
        }
        _ => {
          if flag {
            cur.push(ch);
          } else {
            ans.push(ch);
          }
        }
      }
    }
    ans
  }
}
