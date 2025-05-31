impl Solution {
  pub fn repeated_character(mut s: String) -> char {
    let (mut ans, mut st) = ('z', vec![0; 26]);
    for x in s.as_bytes() {
      if st[(x - b'a') as usize] == 1 {
        ans = x.clone() as char;
        break;
      }
      st[(x - b'a') as usize] += 1;
    }
    ans
  }
}
