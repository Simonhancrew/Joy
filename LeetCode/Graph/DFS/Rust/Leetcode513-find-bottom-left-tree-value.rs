use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
  pub fn find_bottom_left_value(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
    let (mut hei, mut val) = (0, 0);
    fn dfs(inode: Option<Rc<RefCell<TreeNode>>>, mut h: i32, hei: &mut i32, val: &mut i32) {
      if let Some(node) = inode.as_ref() {
        h += 1;
        dfs(node.borrow().left.clone(), h, hei, val);
        dfs(node.borrow().right.clone(), h, hei, val);
        println!("{},{},{}", h, hei, node.borrow().val);
        if &h > hei {
          *hei = h;
          *val = node.borrow().val;
        }
      }
    }
    dfs(root, 0, &mut hei, &mut val);
    val
  }
}
