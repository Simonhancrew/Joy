const MOD: i32 = 1e9 as i32 + 7;
impl Solution {
  pub fn min_absolute_sum_diff(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
    let mut cp = nums1.clone();
    cp.sort_unstable();
    let (mut sum, mut sub) = (0, 0);
    for i in 0..nums1.len() {
      if nums1[i] == nums2[i] {
        continue;
      }
      let diff = (nums1[i] - nums2[i]).abs();
      sum = (sum + diff) % MOD;
      let (mut l, mut r) = (-1, nums1.len() as i32);
      while l + 1 < r {
        let mid = l + r >> 1;
        if cp[mid as usize] <= nums2[i] {
          l = mid;
        } else {
          r = mid;
        }
      }
      let mut tar = i32::MAX;
      if l != -1 {
        tar = tar.min((nums2[i] - cp[l as usize]).abs());
      }
      if r != nums1.len() as i32 {
        tar = tar.min((nums2[i] - cp[r as usize]).abs());
      }
      if tar < diff {
        sub = sub.max(diff - tar);
      }
    }
    (sum - sub + MOD) % MOD
  }
}
