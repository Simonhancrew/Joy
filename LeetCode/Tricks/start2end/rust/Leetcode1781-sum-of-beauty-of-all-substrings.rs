// 这种可以枚举前点到重点，逐步更新
// 先枚举起点的好处就是可以逐步更新
impl Solution {
  pub fn beauty_sum(s: String) -> i32 {
    let (s, n) = (s.as_bytes(), s.len());
    let mut res = 0;
    for i in 0..n {
      let (mut mp, mut mx) = (vec![0; 26], 0);
      for j in i..n {
        mp[(s[j] - b'a') as usize] += 1;
        mx = mx.max(mp[(s[j] - b'a') as usize]);
        let mut mn = n;
        for k in 0..26 {
          if mp[k] > 0 {
            mn = mn.min(mp[k]);
          }
        }
        res += mx - mn;
      }
    }
    res as i32
  }
}
