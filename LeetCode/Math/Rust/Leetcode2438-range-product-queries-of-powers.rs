impl Solution {
  pub fn product_queries(mut n: i32, queries: Vec<Vec<i32>>) -> Vec<i32> {
    let mut powers = vec![];
    let MOD: i64 = 1e9 as i64 + 7;
    while n != 0 {
      let cur = (n & -n);
      powers.push(cur);
      n -= cur;
    }
    let mut pre_acc = vec![vec![0; powers.len()]; powers.len()];
    for i in 0..powers.len() {
      pre_acc[i][i] = powers[i];
      for j in i + 1..powers.len() {
        pre_acc[i][j] = ((pre_acc[i][j - 1] as i64 * powers[j] as i64) % MOD) as i32;
      }
    }
    let mut ans = vec![];
    for q in queries {
      ans.push(pre_acc[q[0] as usize][q[1] as usize]);
    }
    ans
  }
}
