use std::cell::RefCell;
use std::rc::Rc;
// if let take ownership, unwrap does
// borrow() dont take ownership
impl Solution {
  pub fn range_sum_bst(root: Option<Rc<RefCell<TreeNode>>>, low: i32, high: i32) -> i32 {
    if let None = root.clone() {
      return 0;
    }
    let mut ans = 0;
    if let Some(node) = root.clone() {
      ans += Self::range_sum_bst(node.borrow().left.clone(), low, high);
      if node.borrow().val >= low && node.borrow().val <= high {
        ans += node.borrow().val;
      }
      ans += Self::range_sum_bst(node.borrow().right.clone(), low, high);
    }
    ans
  }
}
