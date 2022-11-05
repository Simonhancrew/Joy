impl Solution {
  pub fn parse_bool_expr(s: String) -> bool {
      let (s, mut i) = (s.as_bytes(), 0);
      fn dfs(s: &[u8], i : &mut usize)-> bool {
          if s[*i] == b't' {
              *i += 1;
              return true;
          }
          if s[*i] == b'f' {
              *i += 1;
              return false;
          }
          let op = s[*i];
          *i += 2;
          let mut res = true;
          if op == b'|' {
              res = false;
          }
          while *i < s.len() && s[*i] != b')' {
              if s[*i] == b',' {
                  *i += 1;
              }
              let t = dfs(s, i);
              if op == b'|' {
                  res |= t;
              } else {
                  res &= t;
              }
          }
          *i += 1;
          if op == b'!' {
              res = !res;
          }
          res
      }
      dfs(s, &mut i)
  }
}