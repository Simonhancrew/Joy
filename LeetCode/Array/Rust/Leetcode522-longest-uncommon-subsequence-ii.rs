impl Solution {
  pub fn find_lu_slength(strs: Vec<String>) -> i32 {
    let (n, mut res) = (strs.len(), -1);
    fn check(a: &str, b: &str) -> bool {
      let (a, b) = (a.as_bytes(), b.as_bytes());
      let n = a.len();
      let mut j = 0;
      for i in 0..b.len() {
        if j < n && a[j] == b[i] {
          j += 1;
        }
      }
      j == n
    }
    for i in 0..n {
      let mut flag = false;
      for j in 0..n {
        if i != j && check(&strs[i], &strs[j]) {
          flag = true;
          break;
        }
      }
      if !flag {
        res = res.max(strs[i].len() as i32);
      }
    }
    res
  }
}
