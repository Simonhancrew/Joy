impl Solution {
  pub fn busy_student(start_time: Vec<i32>, end_time: Vec<i32>, query_time: i32) -> i32 {
    let (mut ans, n) = (0, end_time.len());
    for i in 0..n {
      if query_time >= start_time[i] && query_time <= end_time[i] {
        ans += 1;
      }
    }
    ans
  }
}
