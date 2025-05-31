impl Solution {
  pub fn min_max_game(mut nums: Vec<i32>) -> i32 {
    let mut n = nums.len();
    if n == 1 {
      return nums[0];
    }
    n /= 2;
    while n != 0 {
      let mut arr = vec![0; n];
      for i in 0..n {
        if i % 2 == 0 {
          arr[i] = nums[i * 2].min(nums[i * 2 + 1]);
        } else {
          arr[i] = nums[i * 2].max(nums[i * 2 + 1]);
        }
      }
      nums = arr;
      n /= 2;
    }
    nums[0]
  }
}
