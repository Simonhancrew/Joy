use std::cell::RefCell;
use std::collections::VecDeque;
use std::rc::Rc;
impl Solution {
    pub fn largest_values(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32> {
        let mut ans: Vec<i32> = vec![];
        if let None = root {
            return ans;
        }
        let mut q: VecDeque<Rc<RefCell<TreeNode>>> = VecDeque::new();
        q.push_back(root.unwrap().clone());
        while !q.is_empty() {
            let (n, mut cur) = (q.len(), -3e9 as i32);
            for _i in 0..n {
                let t = q.pop_front().unwrap().clone();
                cur = cur.max(t.borrow().val);
                if let Some(node) = &(t.clone().borrow().left) {
                    q.push_back(node.clone());
                }
                if let Some(node) = &(t.clone().borrow().right) {
                    q.push_back(node.clone());
                }
            }
            ans.push(cur);
        }
        ans
    }
}
