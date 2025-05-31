impl Solution {
  pub fn array_nesting(nums: Vec<i32>) -> i32 {
    let (mut ans, n) = (0, nums.len());
    let mut st = vec![false; n];
    for i in 0..n {
      if st[i] {
        continue;
      }
      let (mut ne, mut cur) = (i, 0);
      while !st[ne] {
        cur += 1;
        st[ne] = true;
        ne = nums[ne] as usize;
      }
      ans = ans.max(cur);
    }
    ans
  }
}
