impl Solution {
  pub fn get_maximum_consecutive(mut coins: Vec<i32>) -> i32 {
      coins.sort_unstable();
      let mut ans = 0;
      for &c in &coins {
          if c > ans + 1 {
              return ans + 1;
          }
          ans += c;
      }
      ans + 1
  }
}