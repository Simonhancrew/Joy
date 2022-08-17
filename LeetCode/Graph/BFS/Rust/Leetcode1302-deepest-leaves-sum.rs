use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;
impl Solution {
    pub fn deepest_leaves_sum(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut q = VecDeque::new();
        let mut ans = 0;
        q.push_back(root);
        while !q.is_empty() {
            let n = q.len();
            ans = 0;
            for i in 0..n {
                let t = q.pop_front().unwrap();
                ans += t.unwrap().borrow().val;
                if t.unwrap().borrow().left.is_some() {
                    q.push_back(t.unwrap().borrow().left.clone())
                }
                if t.unwrap().borrow().right.is_some() {
                    q.push_back(t.unwrap().borrow().right.clone());
                }
            }
        }
        ans
    }
}
