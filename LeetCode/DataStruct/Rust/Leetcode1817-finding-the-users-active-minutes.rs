impl Solution {
  pub fn finding_users_active_minutes(mut logs: Vec<Vec<i32>>, k: i32) -> Vec<i32> {
    logs.sort_unstable();
    use std::collections::HashSet;
    let mut ans = vec![0; k as usize];
    let (mut i, n) = (0, logs.len());
    while i < n {
      let mut j = i;
      let mut st = HashSet::new();
      while j < n && logs[j][0] == logs[i][0] {
        st.insert(logs[j][1]);
        j += 1;
      }
      i = j;
      ans[st.len() - 1] += 1;
    }
    ans
  }
}
