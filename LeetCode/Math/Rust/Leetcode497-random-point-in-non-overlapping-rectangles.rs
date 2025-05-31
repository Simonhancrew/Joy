use rand::Rng;
struct Solution {
  rec: Vec<Vec<i32>>,
  s: Vec<i32>,
}
impl Solution {
  fn new(rects: Vec<Vec<i32>>) -> Self {
    let mut s = vec![0];
    for x in &rects {
      let dx = x[2] - x[0] + 1;
      let dy = x[3] - x[1] + 1;
      s.push(s.last().unwrap() + dx * dy);
    }
    Self { rec: rects, s: s }
  }

  fn pick(&self) -> Vec<i32> {
    let mut rng = rand::thread_rng();
    let tar = rng.gen_range(1, self.s.last().unwrap() + 1);
    let (mut l, mut r) = (1, self.rec.len());
    while l < r {
      let mid = (l + r) >> 1;
      if self.s[mid] >= tar {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    let t = &self.rec[r - 1];
    let dx = t[2] - t[0] + 1;
    let dy = t[3] - t[1] + 1;
    return vec![rng.gen_range(0, dx) + t[0], rng.gen_range(0, dy) + t[1]];
  }
}
