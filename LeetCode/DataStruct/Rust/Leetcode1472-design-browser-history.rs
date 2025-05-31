struct BrowserHistory {
  arr: Vec<String>,
  cur: usize,
}

/**
* `&self` means the method takes an immutable reference.
* If you need a mutable reference, change it to `&mut self` instead.
*/
impl BrowserHistory {
  fn new(homepage: String) -> Self {
    Self {
      arr: vec![homepage],
      cur: 0,
    }
  }

  fn visit(&mut self, url: String) {
    self.cur += 1;
    self.arr.truncate(self.cur);
    self.arr.push(url)
  }

  fn back(&mut self, steps: i32) -> String {
    self.cur = self.cur.saturating_sub(steps as usize);
    self.arr[self.cur].clone()
  }

  fn forward(&mut self, steps: i32) -> String {
    self.cur = (self.arr.len() - 1).min(self.cur + steps as usize);
    self.arr[self.cur].clone()
  }
}
