impl Solution {
  pub fn sum_distance(nums: Vec<i32>, s: String, d: i32) -> i32 {
      let n = s.len();
      let mut aft = vec![0i64;n];
      for (i, &c) in s.as_bytes().iter().enumerate() {
          if c == b'R' {
              aft[i] = ((nums[i] + d) as i64);
          } else {
              aft[i] = ((nums[i] - d) as i64);
          }
      }
      aft.sort();
      let mut ans = 0i64;
      let MOD = (1e9 as i32 + 7) as i64;
      for i in 1..n {
          let dis = aft[i] - aft[i - 1];
          ans = (ans + i as i64 * (n - i) as i64 % MOD * dis) % MOD;
      }
      ans as i32
  }
}
