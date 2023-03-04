impl Solution {
  pub fn count_triplets(nums: Vec<i32>) -> i32 {
      let (mut res, mut mp) = (0, vec![0;1 << 16]);
      for x in &nums {
          for y in &nums {
              mp[(x & y) as usize] += 1;
          }
      }
      for x in &nums {
          for i in 0..(1 << 16) {
              if (x & i) == 0 {
                  res += mp[i as usize];
              }
          }
      }
      res
  }
}