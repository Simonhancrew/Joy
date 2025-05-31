impl Solution {
  pub fn minimized_string_length(s: String) -> i32 {
    let mut arr = [0; 26];
    for c in s.as_bytes() {
      let idx: usize = (c - b'a') as usize;
      if arr[idx] != 0 {
        continue;
      }
      arr[idx] += 1;
    }
    arr.iter().sum()
  }
}
