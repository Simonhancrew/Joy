impl Solution {
  pub fn advantage_count(mut nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
    nums1.sort();
    let n = nums1.len();
    let mut id = vec![0; n];
    for i in 0..n {
      id[i] = i as i32;
    }
    id.sort_by(|&a, &b| nums2[a as usize].cmp(&nums2[b as usize]));
    let mut ans = vec![0; n];
    let (mut l, mut r) = (0, n - 1);
    for i in 0..n {
      if nums1[i] > nums2[id[l] as usize] {
        ans[id[l] as usize] = nums1[i];
        l += 1;
      } else {
        ans[id[r] as usize] = nums1[i];
        r -= 1;
      }
    }
    ans
  }
}
