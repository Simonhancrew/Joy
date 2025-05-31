impl Solution {
  fn gcd(a: i32, b: i32) -> i32 {
    if b == 0 {
      return a;
    }
    Self::gcd(b, a % b)
  }
  pub fn max_score(nums: Vec<i32>) -> i32 {
    let n = nums.len();
    let mut f = vec![0; 1 << n];
    for i in 0..(1 << n) {
      let mut cnt = 0;
      for j in 0..n {
        if (i >> j) & 1 == 0 {
          cnt += 1;
        }
      }
      if cnt & 1 == 1 {
        continue;
      }
      cnt = cnt / 2 + 1;
      for j in 0..n {
        if (i >> j) & 1 == 1 {
          for k in j + 1..n {
            if (i >> k) & 1 == 1 {
              if (i >> k) & 1 == 1 {
                f[i] = f[i].max(f[i - (1 << k) - (1 << j)] + cnt * Self::gcd(nums[j], nums[k]));
              }
            }
          }
        }
      }
    }
    f[(1 << n) - 1]
  }
}
