impl Solution {
  pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
    let n = nums.len();
    let mut sz = 2;
    for i in 2..n {
      if nums[i] != nums[sz - 2] {
        nums[sz] = nums[i];
        sz += 1;
      }
    }
    sz.min(n) as _
  }
}
