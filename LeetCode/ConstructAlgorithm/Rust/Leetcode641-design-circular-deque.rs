struct MyCircularDeque {
  hh: i32,
  tt: i32,
  buf: Vec<i32>,
}

/**
* `&self` means the method takes an immutable reference.
* If you need a mutable reference, change it to `&mut self` instead.
*/
impl MyCircularDeque {
  fn new(k: i32) -> Self {
    MyCircularDeque {
      hh: 0,
      tt: 0,
      buf: vec![0; k as usize + 1],
    }
  }

  fn get(&self, x: i32) -> i32 {
    (x + self.buf.len() as i32) % self.buf.len() as i32
  }

  fn insert_front(&mut self, value: i32) -> bool {
    if self.is_full() {
      return false;
    }
    self.hh = self.get(self.hh - 1);
    self.buf[self.hh as usize] = value;
    true
  }

  fn insert_last(&mut self, value: i32) -> bool {
    if self.is_full() {
      return false;
    }
    self.buf[self.tt as usize] = value;
    self.tt = self.get(self.tt + 1);
    true
  }

  fn delete_front(&mut self) -> bool {
    if self.is_empty() {
      return false;
    }
    self.hh = self.get(self.hh + 1);
    true
  }

  fn delete_last(&mut self) -> bool {
    if self.is_empty() {
      return false;
    }
    self.tt = self.get(self.tt - 1);
    true
  }

  fn get_front(&self) -> i32 {
    if self.is_empty() {
      return -1;
    }
    self.buf[self.hh as usize]
  }

  fn get_rear(&self) -> i32 {
    if self.is_empty() {
      return -1;
    }
    self.buf[self.get(self.tt - 1) as usize]
  }

  fn is_empty(&self) -> bool {
    self.hh == self.tt
  }

  fn is_full(&self) -> bool {
    self.get(self.tt + 1) == self.hh
  }
}
