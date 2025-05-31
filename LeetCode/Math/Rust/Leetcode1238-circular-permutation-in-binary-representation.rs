impl Solution {
  pub fn circular_permutation(n: i32, start: i32) -> Vec<i32> {
    let mut res = vec![0; (1 << n) as usize];
    for i in 0..(1 << n) {
      res[i as usize] = i ^ (i >> 1) ^ start;
    }
    res
  }
}
