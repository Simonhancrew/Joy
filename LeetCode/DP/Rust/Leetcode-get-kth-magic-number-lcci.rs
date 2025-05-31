impl Solution {
  pub fn get_kth_magic_number(k: i32) -> i32 {
    let k = k as usize;
    let (mut ans, mut p3, mut p5, mut p7) = (vec![0; k], 0, 0, 0);
    ans[0] = 1;
    for i in 1..k {
      ans[i] = (ans[p3] * 3).min(ans[p5] * 5).min(ans[p7] * 7);
      if ans[i] == ans[p3] * 3 {
        p3 += 1;
      }
      if ans[i] == ans[p5] * 5 {
        p5 += 1;
      }
      if ans[i] == ans[p7] * 7 {
        p7 += 1;
      }
    }
    ans[k - 1]
  }
}
