impl Solution {
  pub fn trap(height: Vec<i32>) -> i32 {
    let n = height.len();
    let (mut l, mut r) = (vec![0; n], vec![0; n]);
    l[0] = height[0];
    r[n - 1] = height[n - 1];
    for i in 1..n {
      l[i] = l[i - 1].max(height[i]);
    }
    for i in (0..n - 1).rev() {
      r[i] = r[i + 1].max(height[i]);
    }
    let mut ans = 0;
    for i in 1..n - 1 {
      ans += l[i].min(r[i]) - height[i];
    }
    ans
  }
}
