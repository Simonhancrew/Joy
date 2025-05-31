// 每次单纯考虑一遍，l[i]是i左边的元素搬到i的花费
// l[i] = l[i - 1] + cnt, 其中cnt是i左边1的个数
impl Solution {
  pub fn min_operations(boxes: String) -> Vec<i32> {
    if boxes.len() == 1 {
      return vec![0];
    }
    let n = boxes.len();
    let (mut l, mut r, mut ans) = (vec![0; n], vec![0; n], vec![0; n]);
    let boxes = boxes.as_bytes();
    let mut cnt = 0;
    if boxes[0] == b'1' {
      cnt = 1;
    }
    for i in 1..n {
      l[i] = l[i - 1] + cnt;
      if boxes[i] == b'1' {
        cnt += 1;
      }
    }
    cnt = 0;
    if boxes[n - 1] == b'1' {
      cnt = 1;
    }
    for i in (0..=n - 2).rev() {
      r[i] = r[i + 1] + cnt;
      if boxes[i] == b'1' {
        cnt += 1;
      }
    }
    for i in 0..n {
      ans[i] = l[i] + r[i];
    }
    ans
  }
}
