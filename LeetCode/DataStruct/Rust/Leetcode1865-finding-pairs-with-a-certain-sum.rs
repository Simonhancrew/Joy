use std::collections::HashMap;
struct FindSumPairs {
  nums1: Vec<i32>,
  nums2: Vec<i32>,
  mp: HashMap<i32, i32>,
}

impl FindSumPairs {
  fn new(nums1: Vec<i32>, nums2: Vec<i32>) -> Self {
    let mut mp = HashMap::new();
    for x in &nums2 {
      *mp.entry(*x).or_insert(0) += 1;
    }
    FindSumPairs { nums1, nums2, mp }
  }

  fn add(&mut self, index: i32, val: i32) {
    let pre = self.nums2[index as usize];
    self.mp.entry(pre).and_modify(|e| *e -= 1);
    self.nums2[index as usize] += val;
    let cur = self.nums2[index as usize];
    self.mp.entry(cur).and_modify(|e| *e += 1).or_insert(1);
  }

  fn count(&self, tot: i32) -> i32 {
    let mut ans = 0;
    for x in &self.nums1 {
      if let Some(&count) = self.mp.get(&(tot - x)) {
        ans += count;
      }
    }
    ans
  }
}
