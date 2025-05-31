impl Solution {
  pub fn validate_stack_sequences(pushed: Vec<i32>, popped: Vec<i32>) -> bool {
    let (mut ans, n) = (vec![], pushed.len());
    let mut j = 0;
    for i in 0..n {
      ans.push(pushed[i]);
      while !ans.is_empty() && ans[ans.len() - 1] == popped[j] {
        j += 1;
        ans.pop();
      }
    }
    ans.is_empty()
  }
}
