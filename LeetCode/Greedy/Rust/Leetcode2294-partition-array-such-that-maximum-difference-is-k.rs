impl Solution {
  pub fn partition_array(mut nums: Vec<i32>, k: i32) -> i32 {
    nums.sort_unstable();
    let (mut cnt, mut pre) = (1, nums[0]);
    for i in 0..nums.len() {
      if nums[i] - pre > k {
        cnt += 1;
        pre = nums[i];
      }
    }
    cnt
  }
}
