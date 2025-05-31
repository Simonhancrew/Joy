impl Solution {
  pub fn min_domino_rotations(tops: Vec<i32>, bottoms: Vec<i32>) -> i32 {
    let calcu = |tar| -> i32 {
      let (mut x, mut y) = (0, 0);
      for i in 0..tops.len() {
        if tops[i] != tar && bottoms[i] != tar {
          return i32::MAX;
        }
        if tops[i] != tar {
          x += 1;
        } else if bottoms[i] != tar {
          y += 1;
        }
      }
      x.min(y)
    };
    let ans = calcu(tops[0]).min(calcu(bottoms[0]));
    if ans == i32::MAX {
      -1
    } else {
      ans
    }
  }
}
