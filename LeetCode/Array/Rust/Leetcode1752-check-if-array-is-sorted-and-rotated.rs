// 前半个数组有序，后半个数组有序。
// 还要保证后半个数组的最大值小于前半个数组的最小值
impl Solution {
  pub fn check(nums: Vec<i32>) -> bool {
    let (n, mut idx) = (nums.len(), 0);
    for i in 1..n {
      if nums[i - 1] > nums[i] {
        idx = i;
        break;
      }
    }
    if idx == 0 {
      return true;
    }
    for i in idx + 1..n {
      if nums[i - 1] > nums[i] {
        return false;
      }
    }
    nums[0] >= nums[n - 1]
  }
}
