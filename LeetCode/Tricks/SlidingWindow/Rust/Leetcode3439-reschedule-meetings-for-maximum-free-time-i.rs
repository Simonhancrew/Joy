impl Solution {
  pub fn max_free_time(event_time: i32, k: i32, start_time: Vec<i32>, end_time: Vec<i32>) -> i32 {
    let n = start_time.len();
    let get = |x: usize| -> i32 {
      if x == 0 {
        return start_time[0];
      }
      if x == n {
        return event_time - end_time[n - 1];
      }
      start_time[x] - end_time[x - 1]
    };
    let (mut ans, mut tmp) = (0, 0);
    for i in 0..=n {
      tmp += get(i);
      if i < k as usize {
        continue;
      }
      ans = ans.max(tmp);
      tmp -= get(i - k as usize);
    }
    ans
  }
}
