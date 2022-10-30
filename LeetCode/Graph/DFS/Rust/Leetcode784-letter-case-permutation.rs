impl Solution {
  pub fn letter_case_permutation(s: String) -> Vec<String> {
      fn dfs(arr: &mut Vec<char>, ret: &mut Vec<String>, idx: usize) {
          if arr.len() == idx {
              ret.push(arr.iter().collect::<String>());
              return;
          }
          if arr[idx].is_ascii_digit() {
              dfs(arr, ret, idx + 1);
              return;
          }
          arr[idx] = arr[idx].to_ascii_uppercase();
          dfs(arr, ret, idx + 1);
          arr[idx] = arr[idx].to_ascii_lowercase();
          dfs(arr, ret, idx + 1);
      }
      let mut ret = vec![];
      dfs(&mut s.chars().collect::<Vec<_>>(), &mut ret, 0);
      ret
  }
}