impl Solution {
  pub fn alphabet_board_path(target: String) -> String {
      let mut res = String::new();
      let mut p = (0, 0);
      for c in target.as_bytes() {
          let (x, y) = ((c - b'a') / 5, (c - b'a') % 5);
          if c == &b'z' {
              if p.1 > y {
                  res += &"L".repeat((p.1 - y) as usize);
              } else {
                  res += &"R".repeat((y - p.1) as usize);
              }
              if p.0 > x {
                  res += &"U".repeat((p.0 - x) as usize);
              } else {
                  res += &"D".repeat((x - p.0) as usize);
              }
          } else {
              if p.0 > x {
                  res += &"U".repeat((p.0 - x) as usize);
              } else {
                  res += &"D".repeat((x - p.0) as usize);
              }
              if p.1 > y {
                  res += &"L".repeat((p.1 - y) as usize);
              } else {
                  res += &"R".repeat((y - p.1) as usize);
              }                
          }
          p = (x, y);
          res += "!";
      }

      res
  }
}