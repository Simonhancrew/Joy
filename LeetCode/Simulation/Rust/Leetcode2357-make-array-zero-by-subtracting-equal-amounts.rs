impl Solution {
  pub fn minimum_operations(mut nums: Vec<i32>) -> i32 {
    let (n, mut res, mut cur) = (nums.len(), 0, 0);
    nums.sort_unstable();
    for i in 0..n {
      if nums[i] == cur {
        continue;
      }
      if nums[i] > cur {
        cur = nums[i];
        res += 1;
      }
    }
    res
  }
}
