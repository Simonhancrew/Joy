impl Solution {
  pub fn max_length_between_equal_characters(s: String) -> i32 {
    let mut rec = vec![-1; 26];
    let s = s.as_bytes();
    let (n, mut ans) = (s.len(), -1);
    for i in 0..n {
      if rec[(s[i] - b'a') as usize] < 0 {
        rec[(s[i] - b'a') as usize] = i as i32;
      } else {
        ans = ans.max(i as i32 - rec[(s[i] - b'a') as usize] - 1);
      }
    }
    ans
  }
}
