use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
  pub fn is_unival_tree(root: Option<Rc<RefCell<TreeNode>>>) -> bool {
    fn is_val(root: Option<Rc<RefCell<TreeNode>>>, val: i32) -> bool {
      if let Some(x) = root {
        x.borrow().val == val && is_val(x.borrow().left.clone(), val) && is_val(x.borrow().right.clone(), val)
      } else {
        true
      }
    }
    let val = root.clone().unwrap().borrow().val;
    is_val(root, val)
  }
}
