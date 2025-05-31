impl Solution {
  pub fn count_even(num: i32) -> i32 {
    let (mut base, last) = (num / 10, num % 10);
    let (mut res, mut acc) = (base * 5, 0);
    while base != 0 {
      acc += base % 10;
      base /= 10;
    }
    if acc & 1 == 1 {
      res += (last + 1) / 2;
    } else {
      res += last / 2 + 1;
    }
    res - 1
  }
}
