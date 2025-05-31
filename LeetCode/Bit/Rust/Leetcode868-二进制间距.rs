impl Solution {
  pub fn binary_gap(mut n: i32) -> i32 {
    let (mut res, mut cur, mut pre) = (0, 0, -1);
    while n != 0 {
      if n & 1 == 1 {
        if pre != -1 {
          res = res.max(cur - pre);
        }
        pre = cur;
      }
      n >>= 1;
      cur += 1;
    }
    res
  }
}
