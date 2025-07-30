impl Solution {
  pub fn longest_subarray(nums: Vec<i32>) -> i32 {
    let (mut ans, mut cur, mut i) = (1, 0, 0);
    while i < nums.len() {
      let mut j = i + 1;
      while j < nums.len() && nums[i] == nums[j] {
        j += 1;
      }
      if nums[i] == cur {
        ans = ans.max(j - i);
      } else if nums[i] > cur {
        cur = nums[i];
        ans = j - i;
      }
      i = j;
    }
    ans as _
  }
}
