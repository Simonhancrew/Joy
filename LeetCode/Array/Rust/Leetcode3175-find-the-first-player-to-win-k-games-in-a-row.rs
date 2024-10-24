impl Solution {
  pub fn find_winning_player(skills: Vec<i32>, k: i32) -> i32 {
      let (mut ans, mut win) = (0, 0);
      for i in 1..skills.len() {
          if win == k {
              break;
          }
          if skills[i] > skills[ans as usize] {
              ans = i as i32;
              win = 0;
          }
          win += 1;
      }
      ans
  }
}