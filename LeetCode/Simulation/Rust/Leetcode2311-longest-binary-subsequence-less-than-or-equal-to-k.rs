impl Solution {
  pub fn longest_subsequence(s: String, k: i32) -> i32 {
    let (n, m) = (s.len(), 32 - k.leading_zeros() as usize);
    if n < m {
      return n as i32;
    }
    let suf_val = i32::from_str_radix(&s[n - m..], 2).unwrap();
    let suf_len = if suf_val <= k { m } else { m - 1 };
    (suf_len + s[..n - m].bytes().filter(|&c| c == b'0').count()) as i32
  }
}
