impl Solution {
  pub fn check_ones_segment(s: String) -> bool {
      let s = s.as_bytes();
      let (mut cnt,mut flag) = (0,false);
      for &c in s.iter() {
          if c == b'1' {
              if flag {
                  continue;
              } else {
                  cnt += 1;
                  if cnt > 1 {
                      return false;
                  }
                  flag = true;
              }
          } else {
              flag = false;
          }
      }
      true
  }
}