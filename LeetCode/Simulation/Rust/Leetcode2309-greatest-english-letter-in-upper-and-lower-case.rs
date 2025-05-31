impl Solution {
  pub fn greatest_letter(s: String) -> String {
    let (n, s) = (s.len(), s.as_bytes());
    let mut ans = vec![];
    let (mut lo, mut up) = (vec![0; 26], vec![0; 26]);
    for i in 0..n {
      if s[i] >= b'a' && s[i] <= b'z' {
        lo[(s[i] - b'a') as usize] += 1;
        if up[(s[i] - b'a') as usize] > 0 && (ans.len() == 0 || ans[0] - b'A' < s[i] - b'a') {
          ans.pop();
          ans.push(s[i] - 32);
        }
      } else {
        up[(s[i] - b'A') as usize] += 1;
        if lo[(s[i] - b'A') as usize] > 0 && (ans.len() == 0 || ans[0] < s[i]) {
          ans.pop();
          ans.push(s[i]);
        }
      }
    }
    String::from_utf8(ans).unwrap()
  }
}
