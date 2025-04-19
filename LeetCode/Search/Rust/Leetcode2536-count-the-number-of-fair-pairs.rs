impl Solution {
  pub fn count_fair_pairs(mut nums: Vec<i32>, lower: i32, upper: i32) -> i64 {
      nums.sort_unstable();
      let n = nums.len();
      let mut ans = 0i64;
      for i in 0..n - 1 {
          let (mut l, mut r) = (i as i32, n as i32);
          while l + 1 < r {
              let mid = (l + r >> 1) as usize;
              if nums[mid] >= lower - nums[i] {
                  r = mid as i32;
              } else {
                  l = mid as i32;
              }
          }
          let pre = r;
          let (mut l, mut r) = (i as i32, n as i32);
          while l + 1 < r {
              let mid = (l + r >> 1) as usize;
              if nums[mid] <= upper - nums[i] {
                  l = mid as i32;
              } else {
                  r = mid as i32;
              }
          }
          ans += (r - pre) as i64;
      }
      ans
  }
}