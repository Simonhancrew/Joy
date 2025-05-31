use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
  pub fn prune_tree(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
    if let None = root {
      return root;
    }
    let r = root.unwrap();
    let lhs = Self::prune_tree(r.borrow_mut().left.take());
    let rhs = Self::prune_tree(r.borrow_mut().right.take());
    if lhs == None && rhs == None && r.borrow().val == 0 {
      return None;
    }
    r.borrow_mut().left = lhs;
    r.borrow_mut().right = rhs;
    Some(r)
  }
}
