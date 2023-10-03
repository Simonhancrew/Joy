impl Solution {
  pub fn max_profit(prices: Vec<i32>) -> i32 {
      let n = prices.len();
      let mut f = vec![0;n + 1];
      let mut pre_min = i32::MAX;
      for i in 1..=n {
          f[i] = f[i - 1].max(prices[i - 1] - pre_min);
          pre_min = pre_min.min(prices[i - 1]);
      }
      let mut ans = 0;
      let mut aft_mx = 0;
      for i in (1..=n).rev() {
          ans = ans.max(aft_mx - prices[i - 1] + f[i - 1]);
          aft_mx = aft_mx.max(prices[i - 1]);
      }
      ans
  }
}