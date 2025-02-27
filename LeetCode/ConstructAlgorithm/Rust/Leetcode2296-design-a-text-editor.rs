struct TextEditor {
  lhs: String,
  rhs: String,
}

impl TextEditor {
  pub fn new() -> Self {
      Self {
          lhs: String::new(),
          rhs: String::new(),
      }
  }

  pub fn add_text(&mut self, text: String) {
      self.lhs.push_str(&text);
  }

  pub fn delete_text(&mut self, k: i32) -> i32 {
      let res = std::cmp::min(k as usize, self.lhs.len());
      self.lhs.truncate(self.lhs.len() - res);
      res as _
  }

  pub fn text(&self) -> String {
      let start = if self.lhs.len() > 10 {
          self.lhs.len() - 10
      } else {
          0
      };
      self.lhs[start..].to_string()
  }

  pub fn cursor_left(&mut self, k: i32) -> String {
      for _ in 0..k {
          if let Some(c) = self.lhs.pop() {
              self.rhs.push(c);
          } else {
              break;
          }
      }
      self.text()
  }

  pub fn cursor_right(&mut self, k: i32) -> String {
      for _ in 0..k {
          if let Some(c) = self.rhs.pop() {
              self.lhs.push(c);
          } else {
              break;
          }
      }
      self.text()
  }
}
