impl Solution {
  pub fn special_array(mut nums: Vec<i32>) -> i32 {
      let n = nums.len();
      nums.sort();
      nums.reverse();
      for i in 1..=n {
          if nums[i - 1] >= i as i32 && (i == n || nums[i] < i as i32) {
              return i as i32;
          }
      }
      -1
  }
}