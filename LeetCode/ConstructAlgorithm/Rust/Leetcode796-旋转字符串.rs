impl Solution {
  pub fn rotate_string(s: String, goal: String) -> bool {
    s.len() == goal.len() && s.repeat(2).contains(&goal)
  }
}
