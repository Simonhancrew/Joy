use std::collections::BTreeMap;
struct MyCalendarThree {
  mp: BTreeMap<i32, i32>,
}

impl MyCalendarThree {
  fn new() -> Self {
    return Self { mp: BTreeMap::new() };
  }

  fn book(&mut self, start: i32, end: i32) -> i32 {
    let (mut res, mut sum) = (0, 0);
    let cnt = self.mp.entry(start).or_insert(0);
    *cnt += 1;
    let cnt = self.mp.entry(end).or_insert(0);
    *cnt -= 1;
    for v in self.mp.values() {
      sum += v;
      res = res.max(sum);
    }
    res
  }
}
