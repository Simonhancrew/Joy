use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
  pub fn lca_deepest_leaves(root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
    fn dfs(node: &Option<Rc<RefCell<TreeNode>>>) -> (i32, Option<Rc<RefCell<TreeNode>>>) {
      match node {
        Some(n) => {
          let n_ref = n.borrow();
          let (left_depth, left_lca) = dfs(&n_ref.left);
          let (right_depth, right_lca) = dfs(&n_ref.right);
          match left_depth.cmp(&right_depth) {
            std::cmp::Ordering::Greater => (left_depth + 1, left_lca),
            std::cmp::Ordering::Less => (right_depth + 1, right_lca),
            std::cmp::Ordering::Equal => (left_depth + 1, Some(Rc::clone(n))),
          }
        }
        None => (0, None),
      }
    }
    let (_, lca) = dfs(&root);
    lca
  }
}
