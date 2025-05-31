impl Solution {
  pub fn num_moves_stones_ii(mut stones: Vec<i32>) -> Vec<i32> {
    let n = stones.len();
    stones.sort();
    let mut res = vec![n as i32, 0];
    let tot = stones[n - 1] - stones[0] + 1 - n as i32; // space
    res[1] = tot - (stones[1] - stones[0] - 1).min(stones[n - 1] - stones[n - 2] - 1);
    let mut j = 0;
    for i in 0..n {
      while stones[i] - stones[j] + 1 > n as i32 {
        j += 1;
      }
      let m = i - j + 1;
      if m == n - 1 && stones[i] - stones[j] == (i - j) as i32 {
        res[0] = res[0].min(2);
      } else {
        res[0] = res[0].min((n - m) as i32);
      }
    }
    res
  }
}
