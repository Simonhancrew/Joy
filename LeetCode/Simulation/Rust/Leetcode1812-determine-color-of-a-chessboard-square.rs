impl Solution {
  pub fn square_is_white(coordinates: String) -> bool {
      let coordinates = coordinates.as_bytes();
      (coordinates[0] - b'a' + 1 + coordinates[1] - b'0') % 2 == 1
  }
}