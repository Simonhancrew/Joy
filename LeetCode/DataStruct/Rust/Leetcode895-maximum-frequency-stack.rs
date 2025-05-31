use std::collections::HashMap;

struct FreqStack {
  freqs: HashMap<i32, usize>,
  stacks: Vec<Vec<i32>>,
}

impl FreqStack {
  fn new() -> Self {
    FreqStack {
      freqs: HashMap::new(),
      stacks: Vec::new(),
    }
  }

  fn push(&mut self, val: i32) {
    self.freqs.entry(val).and_modify(|f| *f += 1).or_insert(0);
    let freq = self.freqs[&val];
    if freq >= self.stacks.len() {
      self.stacks.push(Vec::new());
    }
    self.stacks[freq].push(val);
  }

  fn pop(&mut self) -> i32 {
    let mut last_stack = self.stacks.last_mut().unwrap();
    let val = last_stack.pop().unwrap();
    if last_stack.is_empty() {
      self.stacks.pop();
    }
    *self.freqs.get_mut(&val).unwrap() -= 1;
    return val;
  }
}
