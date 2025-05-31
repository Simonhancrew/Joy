use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;
impl Solution {
  pub fn max_level_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
    if root.is_none() {
      return 0;
    }
    let (mut ans, mut level, mut layer) = (i32::MIN, 0, 0);
    let mut q = VecDeque::new();
    q.push_back(root.clone());
    while !q.is_empty() {
      let (n, mut cur) = (q.len(), 0);
      layer += 1;
      for i in 0..n {
        let t = q.pop_front().unwrap();
        if let Some(node) = t {
          cur += node.borrow().val;
          if !node.borrow().left.is_none() {
            q.push_back(node.borrow_mut().left.take());
          }
          if !node.borrow().right.is_none() {
            q.push_back(node.borrow_mut().right.take());
          }
        }
      }
      if cur > ans {
        ans = cur;
        level = layer;
      }
    }
    level
  }
}
