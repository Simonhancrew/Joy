impl Solution {
  pub fn count_days(mut days: i32, mut meetings: Vec<Vec<i32>>) -> i32 {
    meetings.sort_unstable();
    let (mut start, mut end) = (1, 0);
    for m in meetings {
      if m[0] > end {
        days -= (end - start + 1);
        start = m[0];
      }
      end = end.max(m[1]);
    }
    days - (end - start + 1)
  }
}
