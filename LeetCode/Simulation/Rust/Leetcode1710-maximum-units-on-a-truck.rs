impl Solution {
  pub fn maximum_units(mut box_types: Vec<Vec<i32>>, mut truck_size: i32) -> i32 {
      box_types.sort_by(|a, b| b[1].cmp(&a[1]));
      let mut ans = 0;
      for x in &box_types {
          if x[0] >= truck_size {
              ans += truck_size * x[1];
              break;
          }
          ans += x[0] * x[1];
          truck_size -= x[0];
      }
      ans
  }
}