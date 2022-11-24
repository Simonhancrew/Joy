impl Solution {
  pub fn num_subarray_bounded_max(nums: Vec<i32>, left: i32, right: i32) -> i32 {
      let n = nums.len();
      let calcu = |mx:i32| -> i32 {
          let (mut res, mut i) = (0, 0);
          while i < n {
              if nums[i] > mx {
                  i += 1;
                  continue;
              }
              let mut j = i + 1;
              while j < n && nums[j] <= mx {
                  j += 1;
              }
              let dis = j - i;
              res += (dis + 1) * dis / 2;
              i = j;
          }
          res as i32
      };
      calcu(right) - calcu(left - 1)
  }
}