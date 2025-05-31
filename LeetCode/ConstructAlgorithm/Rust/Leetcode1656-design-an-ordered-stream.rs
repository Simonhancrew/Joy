use std::collections::HashMap;
struct OrderedStream {
  ptr: i32,
  mp: HashMap<i32, String>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl OrderedStream {
  fn new(n: i32) -> Self {
    OrderedStream {
      ptr: 1,
      mp: HashMap::new(),
    }
  }

  fn insert(&mut self, id_key: i32, value: String) -> Vec<String> {
    self.mp.insert(id_key, value);
    let mut ans = vec![];
    if !self.mp.contains_key(&self.ptr) {
      return ans;
    }
    while self.mp.contains_key(&self.ptr) {
      ans.push(self.mp[&self.ptr].clone());
      self.ptr += 1;
    }
    ans
  }
}
