use std::cmp::Reverse;
use std::collections::BinaryHeap;

impl Solution {
  pub fn minimum_difference(nums: Vec<i32>) -> i64 {
    let n = nums.len() / 3;
    let mut fl = vec![0; nums.len()];
    let mut fr = vec![0; nums.len()];

    let mut heap = BinaryHeap::new();
    for i in 0..n {
      fl[n - 1] += nums[i] as i64;
      heap.push(nums[i] as i64);
    }

    for i in n..nums.len() {
      heap.push(nums[i] as i64);
      let top = heap.pop().unwrap();
      fl[i] = fl[i - 1] + nums[i] as i64 - top;
    }

    let mut heap2 = BinaryHeap::new();
    for i in (nums.len() - n)..nums.len() {
      fr[nums.len() - n] += nums[i] as i64;
      heap2.push(Reverse(nums[i] as i64));
    }

    for i in (0..(nums.len() - n)).rev() {
      heap2.push(Reverse(nums[i] as i64));
      let top = heap2.pop().unwrap().0;
      fr[i] = fr[i + 1] + nums[i] as i64 - top;
    }

    let mut ans = i64::MAX;
    for i in (n - 1)..(nums.len() - n) {
      ans = ans.min(fl[i] - fr[i + 1]);
    }

    ans
  }
}
