impl Solution {
  fn check(l: &str, r: &str) -> bool {
    let n = l.len();
    let (mut i, mut j) = (0, n - 1);
    let (l, r) = (l.as_bytes(), r.as_bytes());
    let mut f = false;
    while i < j {
      if f {
        if l[i] != l[j] {
          return false;
        }
      } else {
        if l[i] != r[j] {
          if l[i] != l[j] {
            return false;
          }
          f = true;
        }
      }
      i += 1;
      j -= 1;
    }
    true
  }

  pub fn check_palindrome_formation(mut a: String, mut b: String) -> bool {
    if Self::check(&a, &b) || Self::check(&b, &a) {
      return true;
    }
    a = a.chars().rev().collect();
    b = b.chars().rev().collect();
    Self::check(&a, &b) || Self::check(&b, &a)
  }
}
