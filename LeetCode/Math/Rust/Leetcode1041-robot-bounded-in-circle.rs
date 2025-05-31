impl Solution {
  pub fn is_robot_bounded(instructions: String) -> bool {
    let dx = [0, 1, 0, -1];
    let dy = [1, 0, -1, 0];
    let (mut d, mut x, mut y) = (0, 0, 0);
    for c in instructions.chars() {
      if c == 'L' {
        d = (d - 1 + 4) % 4;
      } else if c == 'R' {
        d = (d + 1) % 4;
      }
      if c == 'G' {
        x = x + dx[d];
        y = y + dy[d];
      }
    }
    x == 0 && y == 0 || d != 0
  }
}
