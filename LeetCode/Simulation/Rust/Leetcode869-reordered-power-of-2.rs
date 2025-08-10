impl Solution {
  pub fn reordered_power_of2(n: i32) -> bool {
    let get = |mut x: i32| -> Vec<i32> {
      let mut res = vec![0; 10];
      while x != 0 {
        res[(x % 10) as usize] += 1;
        x /= 10;
      }
      res
    };
    let (arr, mut i) = (get(n), 1);
    while i <= 1e9 as i32 {
      if arr == get(i) {
        return true;
      }
      i <<= 1;
    }
    false
  }
}
