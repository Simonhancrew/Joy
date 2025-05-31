impl Solution {
  pub fn di_string_match(s: String) -> Vec<i32> {
    let n = s.len();
    let (mut ans, mut l, mut r) = (vec![0 as i32; n + 1], 0, n as i32);
    for (i, x) in s.chars().enumerate() {
      if x == 'I' {
        ans[i] = l;
        l += 1;
      } else {
        ans[i] = r;
        r -= 1;
      }
    }
    ans[n] = l;
    ans
  }
}
