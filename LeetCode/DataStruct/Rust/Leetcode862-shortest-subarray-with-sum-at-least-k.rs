use std::collections::VecDeque;

impl Solution {
  pub fn shortest_subarray(nums: Vec<i32>, k: i32) -> i32 {
    let mut q = VecDeque::new();
    q.push_back(0);
    let n = nums.len();
    let mut s = vec![0 as i64; n + 1];
    for i in 1..=n {
      s[i] = s[i - 1] + nums[i - 1] as i64;
    }
    let mut res = 1000000;
    for i in 1..=n {
      while q.len() != 0 && s[q[0]] + k as i64 <= s[i] {
        res = res.min(i - q[0]);
        q.pop_front();
      }
      while q.len() != 0 && s[q[q.len() - 1]] >= s[i] {
        q.pop_back();
      }
      q.push_back(i as usize);
    }
    if res == 1000000 {
      return -1;
    }
    res as i32
  }
}
