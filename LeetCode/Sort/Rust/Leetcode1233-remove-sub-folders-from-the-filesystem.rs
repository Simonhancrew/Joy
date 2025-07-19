impl Solution {
  pub fn remove_subfolders(mut folder: Vec<String>) -> Vec<String> {
    let mut ans = Vec::new();
    folder.sort_unstable();
    for (i, f) in folder.into_iter().enumerate() {
      if i == 0 {
        ans.push(f);
      } else {
        let lst = ans.last().unwrap();
        if !f.starts_with(lst) || f.as_bytes()[lst.len()] != b'/' {
          ans.push(f);
        }
      }
    }
    ans
  }
}
