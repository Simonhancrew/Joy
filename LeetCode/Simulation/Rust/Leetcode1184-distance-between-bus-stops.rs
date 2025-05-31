impl Solution {
  pub fn distance_between_bus_stops(distance: Vec<i32>, mut start: i32, mut destination: i32) -> i32 {
    if start > destination {
      std::mem::swap(&mut start, &mut destination)
    }
    let (start, destination) = (start as usize, destination as usize);
    distance[start..destination]
      .iter()
      .sum::<i32>()
      .min(distance[0..start].iter().sum::<i32>() + distance[destination..].iter().sum::<i32>())
  }
}
