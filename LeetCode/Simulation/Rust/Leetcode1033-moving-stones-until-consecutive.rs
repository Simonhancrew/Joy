impl Solution {
  pub fn num_moves_stones(a: i32, b: i32, c: i32) -> Vec<i32> {
      let mut tmp = vec![a, b, c];
      tmp.sort();
      let mut ans = vec![0, 0];
      let (l, r) = (tmp[1] - tmp[0] - 1, tmp[2] - tmp[1] - 1);
      ans[0] = 2;
      if l == 0 && r == 0 {
          ans[0] = 0;
      } else if l <= 1 || r <= 1 {
          ans[0] = 1;
      }
      ans[1] = l + r;
      ans
  }
}