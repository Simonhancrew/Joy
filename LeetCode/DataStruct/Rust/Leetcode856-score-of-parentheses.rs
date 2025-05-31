impl Solution {
  pub fn score_of_parentheses(s: String) -> i32 {
    let (n, s) = (s.len(), s.as_bytes());
    let mut stk = vec![0];
    for i in 0..n {
      if s[i] == b'(' {
        stk.push(0);
      } else {
        let t = stk.pop().unwrap();
        let last = stk.len();
        if t == 0 {
          stk[last - 1] += 1;
        } else {
          stk[last - 1] += 2 * t;
        }
      }
    }
    stk[0]
  }
}
