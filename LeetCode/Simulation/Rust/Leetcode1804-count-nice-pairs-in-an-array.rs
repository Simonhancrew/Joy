impl Solution {
  pub fn count_nice_pairs(nums: Vec<i32>) -> i32 {
    let mut ans = 0;
    let mut mp = std::collections::HashMap::new();
    let rev = |mut num: i32| -> i32 {
      let mut ans = 0;

      while num > 0 {
        ans = ans * 10 + num % 10;
        num /= 10;
      }

      ans
    };

    for num in nums {
      let mun = num - rev(num);
      let cnt = *mp.get(&mun).unwrap_or(&0);
      ans = (ans + cnt) % 1000000007;
      mp.insert(mun, cnt + 1);
    }

    ans
  }
}
