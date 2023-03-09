impl Solution {
  pub fn minimum_recolors(blocks: String, k: i32) -> i32 {
      let n = blocks.len();
      let mut res = i32::MAX;
      let (mut j, mut cur) = (0, 0);
      for i in 0..=(n - k as usize) {
          while j - i + 1 <= k as usize {
              if blocks.as_bytes()[j] == b'W' {
                  cur += 1;
              }
              j += 1;
          }
          res = res.min(cur);
          if blocks.as_bytes()[i] == b'W' {
              cur -= 1;
          }
      }
      res
  }
}