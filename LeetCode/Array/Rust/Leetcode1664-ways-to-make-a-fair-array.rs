impl Solution {
  pub fn ways_to_make_fair(nums: Vec<i32>) -> i32 {
      let n = nums.len();
      let (mut s1, mut s2) = (vec![0;n + 1], vec![0;n + 1]);
      for i in 1..=n {
          s1[i] = s1[i - 1];
          s2[i] = s2[i - 1];
          if i % 2 == 1 {
              s1[i] += nums[i - 1];
          } else {
              s2[i] += nums[i - 1];
          }
      }
      let mut res = 0;
      for i in 1..=n {
          let (odd, even) = (s1[i - 1] + s2[n] - s2[i], s2[i - 1] + s1[n] - s1[i]);
          if odd == even {
              res += 1;
          }
      }
      res
  }
}