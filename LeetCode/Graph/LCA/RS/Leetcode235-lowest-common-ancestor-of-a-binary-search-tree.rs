use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
  pub fn lowest_common_ancestor(
    root: Option<Rc<RefCell<TreeNode>>>,
    p: Option<Rc<RefCell<TreeNode>>>,
    q: Option<Rc<RefCell<TreeNode>>>,
  ) -> Option<Rc<RefCell<TreeNode>>> {
    let mut ans = root;
    while let Some(node) = ans.clone() {
      let node_val = node.borrow().val;
      let p_val = p.as_ref().unwrap().borrow().val;
      let q_val = q.as_ref().unwrap().borrow().val;
      ans = if p_val > node_val && q_val > node_val {
        node.borrow().right.clone()
      } else if p_val < node_val && q_val < node_val {
        node.borrow().left.clone()
      } else {
        break;
      };
    }
    ans
  }
}
