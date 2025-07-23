impl Solution {
  pub fn maximum_gain(s: String, mut x: i32, mut y: i32) -> i32 {
    let (mut a, mut b) = (b'a', b'b');
    if x < y {
      (x, y) = (y, x);
      (a, b) = (b, a);
    }
    let (mut cnt1, mut cnt2, mut ans) = (0, 0, 0);
    for &c in s.as_bytes() {
      if c == a {
        cnt1 += 1;
      } else if c == b {
        if cnt1 > 0 {
          cnt1 -= 1;
          ans += x;
          continue;
        }
        cnt2 += 1;
      } else {
        ans += cnt1.min(cnt2) * y;
        cnt1 = 0;
        cnt2 = 0;
      }
    }
    ans += cnt1.min(cnt2) * y;
    ans
  }
}
