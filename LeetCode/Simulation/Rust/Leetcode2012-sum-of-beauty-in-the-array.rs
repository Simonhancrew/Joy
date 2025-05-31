impl Solution {
  pub fn sum_of_beauties(nums: Vec<i32>) -> i32 {
    let n = nums.len();
    let (mut lmx, mut rmin) = (vec![i32::MIN; n], vec![i32::MAX; n]);
    rmin[n - 1] = nums[n - 1];
    lmx[0] = nums[0];
    for i in (0..=nums.len() - 2).rev() {
      rmin[i] = rmin[i + 1].min(nums[i]);
    }
    let mut acc = 0;
    for i in 1..nums.len() - 1 {
      lmx[i] = lmx[i - 1].max(nums[i]);
      if nums[i] > lmx[i - 1] && nums[i] < rmin[i + 1] {
        acc += 2;
        continue;
      }
      if nums[i] > nums[i - 1] && nums[i] < nums[i + 1] {
        acc += 1;
      }
    }
    acc
  }
}
