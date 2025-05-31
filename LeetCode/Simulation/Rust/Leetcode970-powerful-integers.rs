impl Solution {
  pub fn powerful_integers(x: i32, y: i32, bound: i32) -> Vec<i32> {
    use std::collections::HashSet;
    let mut ans = HashSet::new();
    let qmi = |mut a: i64, mut b: i64| -> i64 {
      let mut res = 1i64;
      while b != 0 {
        if b & 1 == 1 {
          res *= a;
        }
        a = a * a;
        b >>= 1;
      }
      res
    };
    let mut i = 0i64;
    while qmi(x as i64, i) <= bound as i64 - 1 {
      let lhs = qmi(x as i64, i);
      let mut j = 0i64;
      while qmi(y as i64, j) + lhs <= bound as i64 {
        let rhs = qmi(y as i64, j);
        ans.insert((lhs + rhs) as i32);
        if y == 1 {
          break;
        }
        j += 1;
      }
      if x == 1 {
        break;
      }
      i += 1;
    }
    ans.iter().map(|x| *x).collect()
  }
}
