use std::collections::VecDeque;

impl Solution {
  pub fn sum_subarray_mins(arr: Vec<i32>) -> i32 {
    let mut stk = VecDeque::new();
    let n = arr.len();
    let (mut l, mut r) = (vec![0; n], vec![0; n]);
    for i in 0..n {
      while stk.len() != 0 && arr[stk[stk.len() - 1] as usize] > arr[i] {
        stk.pop_back();
      }
      if stk.len() == 0 {
        l[i] = -1;
      } else {
        l[i] = stk[stk.len() - 1];
      }
      stk.push_back(i as i64);
    }

    stk.clear();

    for i in (0..n).rev() {
      while stk.len() != 0 && arr[stk[stk.len() - 1] as usize] >= arr[i] {
        stk.pop_back();
      }
      if stk.len() == 0 {
        r[i] = n as i64;
      } else {
        r[i] = stk[stk.len() - 1];
      }
      stk.push_back(i as i64);
    }
    let P = 1e9 as i64 + 7;
    let mut res = 0;
    for i in 0..n {
      res = (res + arr[i] as i64 * (i as i64 - l[i]) % P * (r[i] - i as i64)) % P;
    }
    res as i32
  }
}
