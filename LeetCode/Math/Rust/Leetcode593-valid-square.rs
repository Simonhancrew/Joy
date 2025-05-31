impl Solution {
  pub fn valid_square(p1: Vec<i32>, p2: Vec<i32>, p3: Vec<i32>, p4: Vec<i32>) -> bool {
    let p = vec![p1, p2, p3, p4];
    let mut d = vec![];

    let calcu = |a: &Vec<i32>, b: &Vec<i32>| -> i32 {
      let (dx, dy) = (a[0] - b[0], a[1] - b[1]);
      dx * dx + dy * dy
    };

    for i in 0..4 {
      for j in i + 1..4 {
        d.push(calcu(&p[i], &p[j]));
      }
    }

    d.sort();
    if d[0] == 0 {
      return false;
    }
    d[0] == d[1] && d[0] == d[2] && d[0] == d[3] && d[4] == d[5]
  }
}
