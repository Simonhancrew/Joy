impl Solution {
  pub fn count_hill_valley(mut nums: Vec<i32>) -> i32 {
    // let mut j = 0;
    // for i in 1..nums.len() {
    //     if nums[i] == nums[j] {
    //         continue;
    //     }
    //     j += 1;
    //     nums[j] = nums[i];
    // }
    // nums.truncate(j + 1);
    nums.dedup();
    let mut ans = 0;
    for i in 1..nums.len() - 1 {
      if (nums[i - 1] < nums[i]) == (nums[i] > nums[i + 1]) {
        ans += 1;
      }
    }
    ans
  }
}
