use std::cell::RefCell;
use std::rc::Rc;
impl Solution {
    pub fn delete_node(
        mut root: Option<Rc<RefCell<TreeNode>>>,
        key: i32,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if root.is_none() {
            return None;
        }
        if root.as_ref().unwrap().borrow().val < key {
            let right = root.as_mut().unwrap().borrow_mut().right.take();
            root.as_mut().unwrap().borrow_mut().right = Self::delete_node(right, key);
            return root;
        } else if root.as_ref().unwrap().borrow().val > key {
            let left = root.as_mut().unwrap().borrow_mut().left.take();
            root.as_mut().unwrap().borrow_mut().left = Self::delete_node(left, key);
            return root;
        } else {
            //当前节点就是待删除的节点
            if root.as_ref().unwrap().borrow().left.is_none() {
                return root.as_mut().unwrap().borrow_mut().right.take();
            } else if root.as_ref().unwrap().borrow().right.is_none() {
                return root.as_mut().unwrap().borrow_mut().left.take();
            } else {
                let mut left = root.as_mut().unwrap().borrow_mut().left.take();
                let mut right = root.as_mut().unwrap().borrow_mut().right.take();
                let mut node = right.as_ref().unwrap().as_ptr();
                unsafe {
                    //得到它的最左边的节点
                    while (*node).left.is_some() {
                        node = (*node).left.as_ref().unwrap().as_ptr();
                    }
                    (*node).left = left;
                }
                return right;
            }
        }
    }
}
