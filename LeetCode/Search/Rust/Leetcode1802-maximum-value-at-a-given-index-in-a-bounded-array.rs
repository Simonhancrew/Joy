impl Solution {
  pub fn max_value(n: i32, index: i32, max_sum: i32) -> i32 {
    let (mut l, mut r) = (1, max_sum);
    let calcu = |mx: i64, leng: i64| -> i64 {
      if leng + 1 < mx {
        let mn = mx - leng;
        return (mx - 1 + mn) * leng / 2;
      }
      let cnt = leng - mx + 1;
      (mx - 1) * mx / 2 + cnt
    };
    let check = |mid: i32| -> bool {
      let (lhs_len, rhs_len) = (index as i64, n as i64 - 1 - index as i64);
      mid as i64 + calcu(mid as i64, lhs_len) + calcu(mid as i64, rhs_len) <= max_sum as i64
    };
    while l < r {
      let mid = (l + r + 1) >> 1;
      if check(mid) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    l
  }
}
