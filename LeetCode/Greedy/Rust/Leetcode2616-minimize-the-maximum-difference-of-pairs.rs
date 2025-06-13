impl Solution {
  pub fn minimize_max(mut nums: Vec<i32>, p: i32) -> i32 {
    nums.sort_unstable();
    let (mut l, mut r) = (-1, nums.last().unwrap() - nums[0]);
    let check = |diff| -> bool {
      let (mut cnt, mut i) = (0, 0);
      while i < nums.len() - 1 {
        if nums[i + 1] - nums[i] <= diff {
          cnt += 1;
          i += 1;
        }
        i += 1;
      }
      cnt >= p
    };

    while l + 1 < r {
      let mid = l + r >> 1;
      if check(mid) {
        r = mid;
      } else {
        l = mid;
      }
    }
    r
  }
}
