impl Solution {
  pub fn max_sum(nums: Vec<i32>) -> i32 {
    let mut cnt = vec![-1; 10];
    let get = |mut x| -> usize {
      let mut tar = 0;
      while x != 0 {
        tar = tar.max(x % 10);
        x /= 10;
      }
      tar as _
    };
    let mut ans = -1;
    for x in nums {
      let tar = get(x);
      if cnt[tar] > 0 {
        ans = ans.max(cnt[tar] + x);
      }
      if cnt[tar] < x {
        cnt[tar] = x;
      }
    }
    ans
  }
}
