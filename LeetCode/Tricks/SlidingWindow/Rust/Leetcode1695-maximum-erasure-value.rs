use std::collections::HashSet;
impl Solution {
  pub fn maximum_unique_subarray(nums: Vec<i32>) -> i32 {
    let (mut ans, mut cur) = (0, 0);
    let mut st: HashSet<i32> = HashSet::new();
    let mut j = 0;
    for (i, x) in nums.iter().enumerate() {
      while st.contains(&x) && j < i {
        st.remove(&nums[j]);
        cur -= nums[j];
        j += 1;
      }
      st.insert(*x);
      cur += x;
      ans = ans.max(cur);
    }
    ans
  }
}
