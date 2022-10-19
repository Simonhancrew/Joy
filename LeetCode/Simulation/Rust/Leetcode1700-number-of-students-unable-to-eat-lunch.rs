impl Solution {
  pub fn count_students(students: Vec<i32>, sandwiches: Vec<i32>) -> i32 {
    let mut s1:i32 = students.iter().sum();
    let mut s0 = students.len() as i32 - s1;
    for &val in &sandwiches {
      if val == 1 {
        if s1 != 0 {
          s1 -= 1;
        } else {
          break;
        }
      } else {
        if s0 != 0 {
          s0 -= 1;
        }else {
          break;
        }
      }
    }
    s1 + s0
  }
}