impl Solution {
  pub fn construct_array(n: i32, k: i32) -> Vec<i32> {
    let mut ans = vec![];
    for i in 1..n - k {
      ans.push(i);
    }
    let (mut i, mut j) = (n - k, n);
    while i <= j {
      ans.push(i);
      if i != j {
        ans.push(j);
      }
      i += 1;
      j -= 1;
    }
    ans
  }
}
