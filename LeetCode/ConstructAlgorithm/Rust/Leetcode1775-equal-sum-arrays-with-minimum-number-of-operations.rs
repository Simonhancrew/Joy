use std::mem::swap;
impl Solution {
  pub fn min_operations(mut nums1: Vec<i32>, mut nums2: Vec<i32>) -> i32 {
    if 6 * nums1.len() < nums2.len() || 6 * nums2.len() < nums1.len() {
      return -1;
    }
    let mut d: i32 = nums1.iter().sum::<i32>() - nums2.iter().sum::<i32>();
    if d < 0 {
      swap(&mut nums1, &mut nums2);
      d = -d;
    }
    let (mut cnt, mut ans) = (vec![0; 6], 0);
    nums1.iter().for_each(|&v| cnt[v as usize - 1] += 1);
    nums2.iter().for_each(|&v| cnt[6 - v as usize] += 1);
    for i in (1..=5).rev() {
      if d - i * cnt[i as usize] <= 0 {
        return ans + (d + i - 1) / i;
      }
      d -= cnt[i as usize] * i;
      ans += cnt[i as usize];
    }
    ans
  }
}
