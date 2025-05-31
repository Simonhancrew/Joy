impl Solution {
  pub fn min_operations(logs: Vec<String>) -> i32 {
    let (n, mut stp) = (logs.len(), 0);
    for i in 0..n {
      if logs[i] == "./" || logs[i] == "../" && stp == 0 {
        continue;
      }
      if logs[i] == "../" {
        stp -= 1;
      } else {
        stp += 1;
      }
    }
    stp
  }
}
