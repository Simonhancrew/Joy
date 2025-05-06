impl Solution {
  pub fn build_array(mut nums: Vec<i32>) -> Vec<i32> {
      for i in 0..nums.len() {
          if nums[i] < 0 {
              continue;
          }
          let (mut cur, x) = (i, nums[i]);
          while nums[cur] as usize != i {
              let ne = nums[cur] as usize;
              nums[cur] = !nums[ne];
              cur = ne;
          }
          nums[cur] = !x;
      }
      for i in 0..nums.len() {
          nums[i] = !nums[i];
      }
      nums
  }
}