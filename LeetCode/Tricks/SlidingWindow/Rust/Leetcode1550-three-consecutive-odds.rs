impl Solution {
  pub fn three_consecutive_odds(arr: Vec<i32>) -> bool {
    let (mut l, mut cnt) = (0usize, 0);
    for i in 0..arr.len() {
      if arr[i] & 1 != 0 {
        cnt += 1;
      }
      if cnt == 3 {
        return true;
      }
      if i >= 2 {
        cnt -= (arr[l] & 1);
        l += 1;
      }
    }
    false
  }
}
