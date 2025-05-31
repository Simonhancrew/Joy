impl Solution {
  pub fn partition_disjoint(nums: Vec<i32>) -> i32 {
    let n = nums.len();
    let (mut lmx, mut rmn) = (vec![0; n], vec![0; n]);
    lmx[0] = nums[0];
    rmn[n - 1] = nums[n - 1];
    for i in 1..n {
      lmx[i] = lmx[i - 1].max(nums[i]);
    }
    for i in (0..n - 1).rev() {
      rmn[i] = rmn[i + 1].min(nums[i]);
    }
    let mut ans = 1;
    for i in 0..n - 1 {
      if lmx[i] <= rmn[i + 1] {
        break;
      }
      ans += 1;
    }
    ans
  }
}
