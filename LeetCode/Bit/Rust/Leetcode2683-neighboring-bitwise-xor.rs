impl Solution {
  pub fn does_valid_array_exist(derived: Vec<i32>) -> bool {
    derived.into_iter().reduce(|xor, x| xor ^ x).unwrap() == 0
  }
}
