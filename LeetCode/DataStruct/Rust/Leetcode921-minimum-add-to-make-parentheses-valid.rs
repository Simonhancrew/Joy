impl Solution {
  pub fn min_add_to_make_valid(s: String) -> i32 {
    let (s, mut l, mut r) = (s.as_bytes(), 0, 0);
    for &c in s.iter() {
      if c == b'(' {
        l += 1;
      } else if c == b')' {
        if l == 0 {
          r += 1;
        } else {
          l -= 1;
        }
      }
    }
    l + r
  }
}
