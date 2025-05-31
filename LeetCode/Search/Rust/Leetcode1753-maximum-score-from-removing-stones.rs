impl Solution {
  pub fn maximum_score(a: i32, b: i32, c: i32) -> i32 {
    let sum = a + b + c;
    let mx = a.max(b).max(c);
    if sum - mx < mx {
      return sum - mx;
    }
    sum / 2
  }
}
