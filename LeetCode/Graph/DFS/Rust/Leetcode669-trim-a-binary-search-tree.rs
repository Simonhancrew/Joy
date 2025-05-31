use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
  pub fn trim_bst(root: Option<Rc<RefCell<TreeNode>>>, low: i32, high: i32) -> Option<Rc<RefCell<TreeNode>>> {
    if let Some(r) = root {
      if r.borrow().val > high {
        return Self::trim_bst(r.borrow_mut().left.take(), low, high);
      }

      if r.borrow().val < low {
        return Self::trim_bst(r.borrow_mut().right.take(), low, high);
      }

      let left = Self::trim_bst(r.borrow_mut().left.take(), low, high);
      let right = Self::trim_bst(r.borrow_mut().right.take(), low, high);

      r.borrow_mut().left = left;
      r.borrow_mut().right = right;

      Some(r)
    } else {
      None
    }
  }
}
