impl Solution {
  pub fn maximum_wealth(accounts: Vec<Vec<i32>>) -> i32 {
    let mut mx = 0;
    for x in accounts.iter() {
      mx = mx.max(x.iter().sum());
    }
    mx
  }
}
