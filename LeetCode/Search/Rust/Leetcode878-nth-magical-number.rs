impl Solution {
  pub fn nth_magical_number(n: i32, a: i32, b: i32) -> i32 {
    let (mut l, mut r) = (0i64, 4e13 as i64);
    fn gcd(a: i64, b: i64) -> i64 {
      if b == 0 {
        return a;
      }
      gcd(b, a % b)
    }
    fn get(tar: i64, a: i64, b: i64) -> i64 {
      tar / a + tar / b - tar / (a * b / gcd(a, b))
    }
    while l < r {
      let mid = (l + r) >> 1;
      if get(mid, a as i64, b as i64) >= n as i64 {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    (l % (1e9 as i64 + 7i64)) as i32
  }
}
