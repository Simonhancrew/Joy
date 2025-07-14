impl Solution {
  pub fn get_decimal_value(mut head: Option<Box<ListNode>>) -> i32 {
    let mut ans = 0;
    while let Some(node) = head {
      let cur = node.val;
      ans <<= 1;
      ans |= cur;
      head = node.next;
    }
    ans
  }
}
