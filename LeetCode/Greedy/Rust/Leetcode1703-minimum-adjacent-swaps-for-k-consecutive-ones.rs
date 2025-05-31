impl Solution {
  pub fn min_moves(nums: Vec<i32>, k: i32) -> i32 {
    let (mut rec, n) = (vec![], nums.len());
    for i in 0..n {
      if nums[i] == 1 {
        rec.push(i - rec.len());
      }
    }
    let m = rec.len();
    let mut s = vec![0; m + 1];
    for i in 1..=m {
      s[i] = s[i - 1] + rec[i - 1];
    }
    let mut res = usize::MAX;
    for i in k as usize..=m {
      let (l, r) = (i - k as usize + 1, i);
      let mid = (l + r) >> 1;
      let x = rec[mid - 1];
      let (left, right) = (x * (mid - l) - s[mid - 1] + s[l - 1], s[r] - s[mid] - x * (r - mid));
      res = res.min(left + right);
    }
    res as i32
  }
}
