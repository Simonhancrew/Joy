use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn sum_root_to_leaf(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        fn dfs(root: Option<Rc<RefCell<TreeNode>>>, val: i32) -> i32 {
            match root {
                Some(node) => match node.borrow_mut() {
                    mut p => match p.right.is_none() && p.left.is_none() {
                        true => val | p.val,
                        _ => {
                            dfs(p.left.take(), (val | p.val) << 1)
                                + dfs(p.right.take(), (val | p.val) << 1)
                        }
                    },
                },
                _ => 0,
            }
        }
        return dfs(root, 0);
    }
}
