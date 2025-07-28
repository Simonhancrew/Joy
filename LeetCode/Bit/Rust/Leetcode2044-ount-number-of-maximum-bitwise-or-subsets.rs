impl Solution {
  pub fn count_max_or_subsets(nums: Vec<i32>) -> i32 {
    let n = nums.len();
    let (mut tar, mut cnt) = (0, 0);
    for i in 1..(1 << n) {
      let mut cur = 0;
      for j in 0..n {
        if (i >> j) & 1 == 1 {
          cur |= nums[j];
        }
      }
      if cur > tar {
        tar = cur;
        cnt = 1;
      } else if cur == tar {
        cnt += 1;
      }
    }
    cnt
  }
}
