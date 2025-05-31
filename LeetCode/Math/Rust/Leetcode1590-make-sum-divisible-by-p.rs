impl Solution {
  pub fn min_subarray(nums: Vec<i32>, p: i32) -> i32 {
    let mut x = 0;
    for val in nums.iter() {
      x = (x + val) % p;
    }
    if x == 0 {
      return 0;
    }
    use std::collections::HashMap;
    let mut mp = HashMap::new();
    mp.insert(0, -1);
    let mut y = 0;
    let n = nums.len();
    let mut res = n as i32;
    for i in 0..n {
      y = (y + nums[i]) % p;
      let tar = (y + p - x) % p;
      if mp.contains_key(&tar) {
        res = res.min(i as i32 - mp.get(&tar).unwrap());
      }
      mp.entry(y).and_modify(|v| *v = i as i32).or_insert(i as i32);
    }
    if res == n as i32 {
      -1
    } else {
      res
    }
  }
}
