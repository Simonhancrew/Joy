impl Solution {
  pub fn min_flips_mono_incr(s: String) -> i32 {
    let (mut f0, mut f1) = (0, 0);
    for &c in s.as_bytes() {
      let (mut ff0, mut ff1) = (f0, f0.min(f1));
      if c == b'1' {
        ff0 += 1
      } else {
        ff1 += 1
      }
      f0 = ff0;
      f1 = ff1;
    }
    f1.min(f0)
  }
}
