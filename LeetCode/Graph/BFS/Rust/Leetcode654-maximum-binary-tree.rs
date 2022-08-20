use std::rc::Rc;
use std::cell::RefCell;
impl Solution {
    pub fn construct_maximum_binary_tree(nums: Vec<i32>) -> Option<Rc<RefCell<TreeNode>>> {
        fn dfs(nums: &[i32]) -> Option<Rc<RefCell<TreeNode>>> {
            if nums.is_empty() {
                return None;
            }
            let max = nums.iter().enumerate().max_by_key(|(_, &v)| v).unwrap();
            let node = Rc::new(RefCell::new(TreeNode::new(*max.1)));
            node.as_ref().borrow_mut().left = dfs(&nums[0..max.0]);
            node.as_ref().borrow_mut().right = dfs(&nums[max.0 + 1..]);
            Some(node)
        }
        dfs(&nums[..])    }
}