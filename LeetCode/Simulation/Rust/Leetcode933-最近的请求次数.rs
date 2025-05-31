use std::collections::VecDeque;
struct RecentCounter {
  q: VecDeque<i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RecentCounter {
  fn new() -> Self {
    RecentCounter { q: VecDeque::new() }
  }

  fn ping(&mut self, t: i32) -> i32 {
    self.q.push_back(t);
    while let Some(x) = self.q.front() {
      if t - x > 3000 {
        self.q.pop_front();
      } else {
        break;
      }
    }
    self.q.len() as i32
  }
}
