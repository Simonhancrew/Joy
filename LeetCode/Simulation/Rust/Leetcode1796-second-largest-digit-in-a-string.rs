impl Solution {
  pub fn second_highest(s: String) -> i32 {
      let s = s.as_bytes();
      let (mut mx, mut smx) = (-1, -1);
      for &x in s {
          if x < b'0' || x > b'9' {
              continue;
          }
          let c = (x - b'0') as i32;
          if mx < c {
              smx = mx;
              mx = c;
          } else if c != mx && c > smx {
              smx = c;
          }
      }
      smx
  }
}