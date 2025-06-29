impl Solution {
  pub fn num_subseq(mut nums: Vec<i32>, target: i32) -> i32 {
    nums.sort_unstable();
    let MOD = 1e9 as i64 + 7;
    let (mut l, mut r) = (0, nums.len() - 1);
    let qpow = |mut x| {
      let (mut res, mut base) = (1, 2);
      while x != 0 {
        if x & 1 == 1 {
          res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        x >>= 1;
      }
      res
    };
    let mut res = 0i64;
    while l <= r {
      if nums[l] + nums[r] <= target {
        res = (res + qpow((r - l) as i64)) % MOD;
        l += 1;
      } else {
        if r == 0 {
          break;
        }
        r -= 1;
      }
    }
    res as _
  }
}
