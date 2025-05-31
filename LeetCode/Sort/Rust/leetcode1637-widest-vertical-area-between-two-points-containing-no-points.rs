impl Solution {
  pub fn max_width_of_vertical_area(mut points: Vec<Vec<i32>>) -> i32 {
    points.sort();
    let (mut ans, n) = (0, points.len());
    for i in 1..n {
      ans = ans.max(points[i][0] - points[i - 1][0]);
    }
    ans
  }
}
